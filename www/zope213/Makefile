# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/ \
		http://www.zope.org/Products/Zope/Hotfix_2001-02-23/
DISTNAME=	Zope-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Hotfix_2001-02-23.tgz

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15

#RUN_DEPENDS=	${LOCALBASE}/sbin/apache:${PORTSDIR}/www/apache13-modssl

DIST_SUBDIR=	zope

# Build has to be done in the final location after installing the sources
# there. It were a major action to fix all paths otherwise.
do-build:	# empty, but needs to be there for the python dependency.

# Change these, if you like, via the environment.
WEBBASEDIR?=	www
SZOPEBASEDIR?=	${WEBBASEDIR}/Zope
SCGIBINDIR?=	${WEBBASEDIR}/cgi-bin.default
APACHE_CONFDIR?=	${PREFIX}/etc/apache
PYTHON15?=	${LOCALBASE}/bin/python1.5

WHOAMI!=	id -un
.if ${WHOAMI} == "root"
NOBODY_USER?=	nobody
.else
NOBODY_USER?=	${WHOAMI}
.endif

# Don't change these.
ZOPEBASEDIR=	${PREFIX}/${SZOPEBASEDIR}
CGIBINDIR=	${PREFIX}/${SCGIBINDIR}

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR} \
		CGIBINDIR=${SCGIBINDIR} \
		VERSION=${PORTVERSION}

# I decided to consider the whole souce tree to be part of the package
# since in there, Zope can live on its own. It does leave some *.o files
# around (about four), but I can use Zope's own building mechanism.
do-install:	#
	@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
		${ECHO} "Saving existing Database to /tmp/Data.fs.BAK." ; \
		${MV} ${ZOPEBASEDIR}/var/Data.fs /tmp/Data.fs.BAK ; \
		fi
	@#
	@${MKDIR} ${ZOPEBASEDIR}
	@${ECHO} "===>   Please be patient, some builds need their time."
	@${ECHO} "===>   Copying..."
	@${CP} -Rp ${WRKSRC}/* ${ZOPEBASEDIR}/
	@${CP} -Rp ${WRKDIR}/lib ${ZOPEBASEDIR}/
	@#
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON15} w_pcgi.py)
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON15} wo_pcgi.py)
	@(cd ${ZOPEBASEDIR} && \
		${MV} Zope.cgi Zope.cgi.orig ; \
		${ECHO} "#! ${CGIBINDIR}/pcgi-wrapper" > Zope.cgi ; \
		${CAT} Zope.cgi.orig >> Zope.cgi )
	@#
	@${MKDIR} ${CGIBINDIR}
	@(cd ${ZOPEBASEDIR} ; \
		${INSTALL} -m 555 Zope.cgi \
			pcgi/pcgi-wrapper \
			${CGIBINDIR} )
	@#
	@${ECHO} "===>   Fixing permissions of Zope's own var directory..."
	@${CHMOD} ugo+rwt ${ZOPEBASEDIR}/var
	@${CHOWN} ${NOBODY_USER} ${ZOPEBASEDIR}/var
	@${CHOWN} ${NOBODY_USER} ${ZOPEBASEDIR}/var/*
	@#
	@${ECHO} "===>   Setting user/password to zopemaster/test..."
	@(cd ${ZOPEBASEDIR} && \
		${PYTHON15} zpasswd.py -u zopemaster \
			-p test -e CLEARTEXT access )
	@#
	@${CHOWN} ${NOBODY_USER} ${ZOPEBASEDIR}/access
	@#
	@${ECHO} "===>   Copying Apache config file changes to ${APACHE_CONFDIR}/apache.conf.Zope-Changes."
	@${MKDIR} ${APACHE_CONFDIR}
	@${CP} -p ${FILESDIR}/apache.conf.Zope-Changes ${APACHE_CONFDIR}/
	@#
	@${ECHO} "===>   Please have a look at this file and the instructions"
	@${ECHO} "===>   therein and incorporate them to your apache.conf."
	@${ECHO} "===>   Creating rc startup file for Zope-${PORTVERSION}..."
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} -e "s|%%ZOPEBASEDIR%%|${ZOPEBASEDIR}|g" -e "s|%%CGIBINDIR%%|${CGIBINDIR}|g" \
		< ${FILESDIR}/zope.sh.in > ${PREFIX}/etc/rc.d/zope.sh
	@${CHMOD} ug+x,o-rwx ${PREFIX}/etc/rc.d/zope.sh
	@${ECHO} "===>  Done with ${PREFIX}/etc/rc.d/zope.sh."
	@${CAT} ${FILESDIR}/Message
	@${ECHO} "===>   Your Zope base directory is ${ZOPEBASEDIR}."
	@${ECHO} "===>   The Zope license is in ${ZOPEBASEDIR}/LICENSE.txt."
	@${ECHO} "===>   For Apache changes see ${APACHE_CONFDIR}/apache.conf.Zope-Changes."
	@${ECHO} "===>   Zope.cgi and pcgi-wrapper live in ${CGIBINDIR}."

#pre-deinstall:	# Save Database contents. I expect /tmp to have sufficient
#		# space to hold it for the time being.
#		@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
#			${ECHO} "Saving existing Database to /tmp/Data.fs.bak." ; \
#			${MV} ${ZOPEBASEDIR}/var/Data.fs /tmp/Data.fs.bak ; \
#			fi

.include <bsd.port.mk>
