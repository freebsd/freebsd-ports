# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.0.0b5
DISTNAME=	Zope-${VERSION}-src
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${VERSION}/
DISTNAME=	Zope-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python
RUN_DEPENDS=	${LOCALBASE}/sbin/apache:${PORTSDIR}/www/apache13-modssl

# Build has to be done in the final location after installing the sources
# there. It were a major action to fix all paths otherwise.
do-build:	# empty, but needs to be there for the python dependency.

# The web server's "root" directory used to be ${PREFIX}/www, and from
# then on, data, cgi-bin and such. Thus, I decided that Zope belongs
# there, too. I don't know whether this still applies to current apache
# releases, though. I still run 2.2.8-STABLE.
PLIST_SUB=	ZOPEBASEDIR=www/Zope-${PORTVERSION} CGIBINDIR=share/apache/cgi-bin VERSION=${PORTVERSION}
WEBBASEDIR?=	${PREFIX}/www
ZOPEBASEDIR?=	${WEBBASEDIR}/Zope-${PORTVERSION}
CGI_BIN_DIR?=	${PREFIX}/share/apache/cgi-bin
APACHE_CONFDIR?=	${PREFIX}/etc/apache
PYTHON15?=	${PREFIX}/bin/python1.5

# I decided to consider the whole souce tree to be part of the package
# since in there, Zope can live on its own. It does leave some *.o files
# around (about four), but I can use Zope's own building mechanism.
do-install:	#
		@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
			${ECHO} "Saving existing Database to /tmp/Data.fs.BAK." ; \
			${MV} ${ZOPEBASEDIR}/var/Data.fs /tmp/Data.fs.BAK ; \
			fi
		@( ${MKDIR} ${ZOPEBASEDIR} ; \
		${ECHO} "===>   Please be patient, some builds need their time." ; \
		${ECHO} "===>   Copying..." ; \
		${CP} -Rp ${WRKSRC}/* ${ZOPEBASEDIR}/ ; \
		cd ${ZOPEBASEDIR} ; \
		${PYTHON15} w_pcgi.py ; \
		${PYTHON15} wo_pcgi.py ; \
		${MV} Zope.cgi Zope.cgi.orig ; \
		${ECHO} "#! ${CGI_BIN_DIR}/pcgi-wrapper" > Zope.cgi ; \
		${CAT} Zope.cgi.orig >> Zope.cgi ; \
		${INSTALL} -o nobody -m 555 Zope.cgi pcgi/pcgi-wrapper ${CGI_BIN_DIR} ; \
		${ECHO} "===>   Fixing permissions of Zope's own var directory..." ; \
		${CHMOD} ugo+rwt var ; \
		${ECHO} "===>   Setting user/password to zopemaster/test..." ; \
		${PYTHON15} zpasswd.py -u zopemaster -p test -e CLEARTEXT access ; \
		${ECHO} "===>   Copying Apache config file changes to ${APACHE_CONFDIR}/apache.conf.Zope-${PORTVERSION}-Changes." ; \
		${CP} -p ${FILESDIR}/apache.conf.Zope-${PORTVERSION}-Changes ${APACHE_CONFDIR}/ ; \
		${ECHO} "===>   Please have a look at this file and the instructions" ; \
		${ECHO} "===>   therein and incorporate them to your apache.conf." ; \
		${ECHO} "===>   Creating rc startup file for Zope-${PORTVERSION}..." ; \
		${ECHO} "#! /bin/sh" > ${PREFIX}/etc/rc.d/zope.sh ; \
		${ECHO} "${ZOPEBASEDIR}/start -w '' -f '' -m '' -p ${CGI_BIN_DIR}/Zope.cgi &" >> ${PREFIX}/etc/rc.d/zope.sh ; \
		${ECHO}	"echo -n \" Zope\"" >> ${PREFIX}/etc/rc.d/zope.sh ; \
		${CHMOD} ug+x,o-rwx ${PREFIX}/etc/rc.d/zope.sh ; \
		${ECHO} "===>  Done with ${PREFIX}/etc/rc.d/zope.sh." ; \
		${CAT} ${FILESDIR}/Message ; \
		${ECHO} "===>   Your Zope base directory is ${ZOPEBASEDIR}." ; \
		${ECHO} "===>   The Zope license is in ${ZOPEBASEDIR}/LICENSE.txt." ; \
		${ECHO} "===>   For Apache changes see ${APACHE_CONFDIR}/apache.conf.Zope-${PORTVERSION}-Changes." ; \
		${ECHO} "===>   Zope.cgi and pcgi-wrapper live in ${CGI_BIN_DIR}." )

#pre-deinstall:	# Save Database contents. I expect /tmp to have sufficient
#		# space to hold it for the time being.
#		@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
#			${ECHO} "Saving existing Database to /tmp/Data.fs.bak." ; \
#			${MV} ${ZOPEBASEDIR}/var/Data.fs /tmp/Data.fs.bak ; \
#			fi

.include <bsd.port.mk>
