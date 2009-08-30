# New ports collection makefile for:	webobjects
# Date created:				Thu Apr 12 04:43:26 EST 2007
# Whom:					Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	webobjects
PORTVERSION=	5.3.3
CATEGORIES=	www java
MASTER_SITES=	#
DISTNAME=	WebObjects5.3.3Update
EXTRACT_SUFX=	.pax.gz

MAINTAINER?=	q@onthenet.com.au
COMMENT=	WebObjects Application Server Runtime ${PORTVERSION}

IS_INTERACTIVE=	yes
RESTRICTED=	License doesn't allow redistribution

WOBINURL=	http://www.apple.com/support/downloads/webobjects533.html
WOPKGBUNDLE=	WebObjects5.3.3Update.dmg
WOBINARCHIVE=	${DISTNAME}${EXTRACT_SUFX}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_RC_SUBR=	wotaskd.sh JavaMonitor.sh
USE_JAVA=	1.4+
USE_PERL5_BUILD=yes

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.plist"

NEXT_ROOT?=	${PREFIX}/apple
NEXT_BASE=	${NEXT_ROOT:S,^${PREFIX}/,,}
NEXT_USER?=	${WWWOWN}
NEXT_GROUP?=	${WWWGRP}
SYSTEM_LIBRARY=	${NEXT_BASE}/Library
LOCAL_LIBRARY=	${NEXT_BASE}/Local/Library
LOCALLIB=	${PREFIX}/${LOCAL_LIBRARY}
WOLOCAL=	${LOCALLIB}/WebObjects
WODOCROOT?=	${WWWDIR}
WODOCROOT_REL=	${WODOCROOT:S,^${PREFIX}/,,}

PLIST_SUB=	NEXT_ROOT=${NEXT_BASE} WODOCROOT=${WODOCROOT_REL}
SUB_LIST+=	NEXT_ROOT=${NEXT_BASE} USER=${NEXT_USER} GROUP=${NEXT_GROUP} \
		JAVA=${JAVA} WODOCROOT=${WODOCROOT_REL}
SUB_FILES+=	pkg-message pkg-install pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

EXTRACT_AFTER_ARGS=| ${TAR} -xpf -
COPYTREE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
	${CHOWN} -R ${BINOWN}:${BINGRP} $$1 && \
	${FIND} $$1 -type d -exec ${CHMOD} 755 {} \;' --

.if defined(WITH_APACHE)
USE_APACHE?=	1.3+
BUILD_DEPENDS+=	${APACHEMODDIR}/mod_WebObjects.so:../../www/mod_webobjects
.endif

# Check for distribution files
.if !defined(PACKAGE_BUILDING) && !exists(${DISTDIR}/${WOBINARCHIVE})
ECHO_MSG=	${PRINTF}
IGNORE=		cannot be downloaded automatically.
IGNORE+=	\n\
Due to licensing restrictions you must download the necessary files manually.\n\
Please open ${WOBINURL} in a\n\
web browser and download the necessary files from Apple.\n\n\
Please place the file ${WOBINARCHIVE} located in the\n\
downloaded file bundle into ${DISTDIR} and restart the build.\n\n
.endif

do-fetch:
	# See http://wiki.objectstyle.org/confluence/display/WO/WebObjects+5.3.3+Deployment+on+FreeBSD+6.x
	# for the gory details.
	dd if=${DISTDIR}/${WOPKGBUNDLE} bs=0x1000 skip=0xb12 of=${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${PERL} -e 'truncate "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}", 29672581'

pre-install:
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/${SYSTEM_LIBRARY}
	@${MKDIR} ${PREFIX}/${LOCAL_LIBRARY}
	@${CHMOD} -R 755 ${PREFIX}/${NEXT_BASE}
	@${ECHO_MSG} -n ">> Installing WebObjects Runtime..."
	@(cd ${WRKSRC}/System/Library && ${COPYTREE} \* \
		${PREFIX}/${SYSTEM_LIBRARY})
	@(cd ${WRKSRC}/Library && ${COPYTREE} \* \
		${PREFIX}/${LOCAL_LIBRARY})
	@${ECHO_MSG} " [ DONE ]"
	@${CHOWN} ${NEXT_USER}:${NEXT_GROUP} ${WOLOCAL}
	@${CHMOD} 0775 ${WOLOCAL}
	@${MKDIR} ${WOLOCAL}/Configuration
	@${MKDIR} ${WOLOCAL}/Applications
	@${MKDIR} ${WOLOCAL}/JavaApplications
	@${MKDIR} ${LOCALLIB}/Frameworks
	@${CHOWN} -R ${NEXT_USER}:${NEXT_GROUP} ${WOLOCAL}/Configuration
	@${CHOWN} ${NEXT_USER}:${NEXT_GROUP} ${WOLOCAL}/Applications
	@${CHOWN} ${NEXT_USER}:${NEXT_GROUP} ${WOLOCAL}/JavaApplications
	@${CHOWN} ${NEXT_USER}:${NEXT_GROUP} ${LOCALLIB}/Frameworks
	@${ECHO_MSG} -n ">> Installing WebObjects Web Resources..."
	@${MKDIR} ${WODOCROOT}
	@(cd ${WRKSRC}/System/Library/WebObjects/WODocumentRoot && \
		${COPYTREE_SHARE} \* ${WODOCROOT})
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@(cd ${WRKSRC}/System/Library && ${PLIST_GEN} \* ${PREFIX}/${SYSTEM_LIBRARY})
	@(cd ${WRKSRC}/Library && ${PLIST_GEN} \* ${PREFIX}/${LOCAL_LIBRARY} "-mindepth 1" )
	@(cd ${WRKSRC}/System/Library/WebObjects/WODocumentRoot && \
		${PLIST_GEN} \* ${WODOCROOT})
	@${PLIST_DIRRM} ${NEXT_BASE}/Library
	@${PLIST_DIRRMTRY} ${WODOCROOT}
	@${PLIST_DIRRMTRY} ${WOLOCAL} Configuration Applications JavaApplications
	@${PLIST_DIRRMTRY} ${NEXT_BASE} Local/Library/Frameworks
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
