# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.3.1
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nbm@FreeBSD.org

USE_PYTHON=	yes

#RUN_DEPENDS=	${LOCALBASE}/sbin/apache:${PORTSDIR}/www/apache13-modssl

DIST_SUBDIR=	zope

# Build has to be done in the final location after installing the sources
# there. It was a major action to fix all paths otherwise.
do-build:	# empty, but needs to be there for the python dependency.

# Change these, if you like, via the environment.
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope
SCGIBINDIR?=		${WEBBASEDIR}/cgi-bin.default
SAPACHE_CONFDIR?=	etc/apache

WHOAMI!=	id -un
.if ${WHOAMI} == "root"
NOBODY_USER?=	nobody
.else
NOBODY_USER?=	${WHOAMI}
.endif

# Don't change these.
ZOPEBASEDIR=	${PREFIX}/${SZOPEBASEDIR}
CGIBINDIR=	${PREFIX}/${SCGIBINDIR}
APACHE_CONFDIR=	${PREFIX}/${SAPACHE_CONFDIR}

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR} \
		CGIBINDIR=${SCGIBINDIR} \
		APACHE_CONFDIR=${SAPACHE_CONFDIR} \
		VERSION=${PORTVERSION} \
		WEBBASEDIR=${WEBBASEDIR}

# I decided to consider the whole souce tree to be part of the package
# since in there, Zope can live on its own. I can use Zope's own building
# mechanism.
do-install:
	@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
		${ECHO} "Saving existing Database to ${ZOPEBASEDIR}/var/Data.fs.preserve." ; \
		${MV} ${ZOPEBASEDIR}/var/Data.fs ${ZOPEBASEDIR}/var/Data.fs.preserve; \
	fi
	@#
	@${MKDIR} ${ZOPEBASEDIR}
	@${ECHO} "===>   Please be patient, some builds need their time."
	@${ECHO} "===>   Copying..."
	@${CP} -Rp ${WRKSRC}/* ${ZOPEBASEDIR}/
	@#${CP} -Rp ${WRKDIR}/lib ${ZOPEBASEDIR}/
	@#
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON_CMD} w_pcgi.py)
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON_CMD} wo_pcgi.py)
	@(cd ${ZOPEBASEDIR} && \
		${MV} Zope.cgi Zope.cgi.orig ; \
		${ECHO} "#! ${CGIBINDIR}/pcgi-wrapper" > Zope.cgi ; \
		${CAT} Zope.cgi.orig >> Zope.cgi ; \
		${RM} Zope.cgi.orig )
	@(cd ${ZOPEBASEDIR}/pcgi/Test && ${RM} *.o)
	@(cd ${ZOPEBASEDIR}/pcgi && ${RM} *.o)
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
	@${RM} ${ZOPEBASEDIR}/var/.cvsignore
	@if [ -e ${ZOPEBASEDIR}/var/Data.fs.preserve ] ; then \
		${ECHO} "Restoring existing Database from ${ZOPEBASEDIR}/var/Data.fs.preserve." ; \
		${MV} ${ZOPEBASEDIR}/var/Data.fs.preserve ${ZOPEBASEDIR}/var/Data.fs; \
	fi
	@#
	@if [ ! -f ${ZOPEBASEDIR}/access ]; then \
		${ECHO} "===>   Setting user/password to zopemaster/test..."; \
		(cd ${ZOPEBASEDIR} && \
			${PYTHON_CMD} zpasswd.py -u zopemaster \
				-p test -e CLEARTEXT access ); \
	fi
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

.include <bsd.port.mk>
