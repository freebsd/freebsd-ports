# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.6.0
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@FreeBSD.org

USE_PYTHON=	yes

DIST_SUBDIR=	zope

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Build has to be done in the final location after installing the sources
# there. It was a major action to fix all paths otherwise.
do-build:	# empty, but needs to be there for the python dependency.

# Change these, if you like, via the environment.
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope
SCGIBINDIR?=		${WEBBASEDIR}/cgi-bin
SAPACHE_CONFDIR?=	etc/apache
ZOPE_HTTP_PORT?=	8080
ZOPE_FTP_PORT?=		8021
ZOPE_MONITOR_PORT?=	''

ZOPE_USER=	www

# Don't change these.
ZOPEBASEDIR=	${PREFIX}/${SZOPEBASEDIR}
CGIBINDIR=	${PREFIX}/${SCGIBINDIR}
APACHE_CONFDIR=	${PREFIX}/${SAPACHE_CONFDIR}

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR} \
		CGIBINDIR=${SCGIBINDIR} \
		APACHE_CONFDIR=${SAPACHE_CONFDIR} \
		VERSION=${PORTVERSION} \
		WEBBASEDIR=${WEBBASEDIR}

# Force the cgi-bin dir or link to exist.
# If we have to create it, call it -dist to emphasize that the port
# set it up. <alane>

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

# I decided to consider the whole souce tree to be part of the package
# since in there, Zope can live on its own. I can use Zope's own building
# mechanism.
do-install:
	@if test ! -d ${CGIBINDIR}; then \
		${ECHO_CMD} "The directory for Zope's CGI scripts does"\
			"not exist, so I will create it.";\
		${ECHO_CMD} "They will be placed in ${CGIBINDIR}.";\
		${ECHO_CMD} ;\
		${MKDIR} ${CGIBINDIR}; ${CHMOD} 0755 ${CGIBINDIR}; fi
	@if [ -e ${ZOPEBASEDIR}/var/Data.fs ] ; then \
		${ECHO} "Saving existing Database to ${ZOPEBASEDIR}/var/Data.fs.preserve." ; \
		${MV} ${ZOPEBASEDIR}/var/Data.fs ${ZOPEBASEDIR}/var/Data.fs.preserve; \
	fi
	@#
	@${MKDIR} ${ZOPEBASEDIR}
	@${ECHO} "===>   Please be patient, some builds need their time."
	@${ECHO} "===>   Copying..."
	@${CP} -Rp ${WRKSRC}/* ${ZOPEBASEDIR}/
	#
	# Copying some patches
	#
	#@${CP} -Rp ${WRKDIR}/lib ${ZOPEBASEDIR}/
	@#
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON_CMD} w_pcgi.py)
	@${CHMOD} -R u+w ${ZOPEBASEDIR}
	@(cd ${ZOPEBASEDIR} && ${PYTHON_CMD} wo_pcgi.py)
	@(cd ${ZOPEBASEDIR} && \
		${MV} Zope.cgi Zope.cgi.orig ; \
		${ECHO_CMD} "#! ${CGIBINDIR}/pcgi-wrapper" > Zope.cgi ; \
		${CAT} Zope.cgi.orig >> Zope.cgi ; \
		${RM} Zope.cgi.orig )
	@(cd ${ZOPEBASEDIR}/pcgi/Test && ${RM} *.o)
	@(cd ${ZOPEBASEDIR}/pcgi && ${RM} *.o)
	@#
	@(cd ${ZOPEBASEDIR} && \
		${MV} Zope.cgi \
			pcgi/pcgi-wrapper \
			${CGIBINDIR} )
	@(cd ${CGIBINDIR} && \
		${CHMOD} 555 Zope.cgi pcgi-wrapper )
	@#
	@${ECHO} "===>   Fixing permissions of Zope's own var directory..."
	@${CHMOD} ugo+rwt ${ZOPEBASEDIR}/var
	@${CHOWN} ${ZOPE_USER} ${ZOPEBASEDIR}/var
	@${CHOWN} ${ZOPE_USER} ${ZOPEBASEDIR}/var/*
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
	@${CHOWN} ${ZOPE_USER} ${ZOPEBASEDIR}/access
	@#
	@${ECHO} "===>   Copying Apache config file changes to ${APACHE_CONFDIR}/apache.conf.Zope-Changes."
	@${MKDIR} ${APACHE_CONFDIR}
	@${CP} -p ${FILESDIR}/apache.conf.Zope-Changes ${APACHE_CONFDIR}/
	@#
	@${ECHO} "===>   Please have a look at this file and the instructions"
	@${ECHO} "===>   therein and incorporate them to your apache.conf."
	@${ECHO} "===>   Creating rc startup file for Zope-${PORTVERSION}..."
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} -e "s|%%ZOPEBASEDIR%%|${ZOPEBASEDIR}|g" \
	        -e "s|%%CGIBINDIR%%|${CGIBINDIR}|g" \
	        -e "s|%%ZOPE_USER%%|${ZOPE_USER}|g" \
		-e "s|%%ZOPE_HTTP_PORT%%|${ZOPE_HTTP_PORT}|g" \
		-e "s|%%ZOPE_FTP_PORT%%|${ZOPE_FTP_PORT}|g" \
		-e "s|%%ZOPE_MONITOR_PORT%%|${ZOPE_MONITOR_PORT}|g" \
		< ${FILESDIR}/zope.sh.in > ${PREFIX}/etc/rc.d/zope.sh
	@${CHMOD} ug+x,o-rwx ${PREFIX}/etc/rc.d/zope.sh
	@${ECHO} "===>  Done with ${PREFIX}/etc/rc.d/zope.sh."
	@${CAT} ${FILESDIR}/Message
	@${ECHO} "===>   Your Zope base directory is ${ZOPEBASEDIR}."
	@${ECHO} "===>   The Zope license is in ${ZOPEBASEDIR}/LICENSE.txt."
	@${ECHO} "===>   For Apache changes see ${APACHE_CONFDIR}/apache.conf.Zope-Changes."
	@${ECHO} "===>   Zope.cgi and pcgi-wrapper live in ${CGIBINDIR}."

.include <bsd.port.mk>
