# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enigmail
PORTVERSION?=	0.91.0
PORTREVISION?=	0
CATEGORIES=	mail security
MASTER_SITES=	\
		http://mozdev.secsup.org/enigmail/src/ \
		http://downloads.us-east3.mozdev.org/enigmail/src/ \
		http://mozdev.oregonstate.edu/enigmail/src/ \
		http://mozdev.sweetooth.org/enigmail/src/ \
		http://ftp.heanet.ie/pub/mozdev/enigmail/src/ \
		http://mirror.meisterwerk.net/rmozdev/enigmail/src/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		ipc-${IPCVERSION}${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	A GnuPG extension for the Mozilla mail client

EXTRACT_DEPENDS?=	${WRKDIR}/../../../${LOCAL_SRCDIR}/work/mozilla/Makefile:${PORTSDIR}/${LOCAL_SRCDIR}:configure
RUN_DEPENDS?=	mozilla:${PORTSDIR}/${LOCAL_SRCDIR}

RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg

IPCVERSION?=	1.1.2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk20 libidl

WRKSRC=		${WRKDIR}/mozilla
LOCAL_SRCDIR?=	www/mozilla
LOCAL_SUBDIR?=	lib/mozilla
LOCAL_PREFIX=	${PREFIX}/${LOCAL_SUBDIR}

COMPONENTS=	ipc.xpt enigmime.xpt libenigmime.so enigmail.xpt enigmail.js enigprefs-service.js
CHROME=		enigmime.jar enigmail.jar enigmail-skin.jar enigmail-skin-tbird.jar
PREF=		enigmail.js

PLIST_SUB=	LOCAL_SUBDIR=${LOCAL_SUBDIR}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${WRKDIR}/../../../${LOCAL_SRCDIR}/work/mozilla ${WRKSRC}
	@for f in ${EXTRACT_ONLY}; do \
		cd ${WRKSRC}/extensions && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS}; \
	done

pre-patch:
	@${REINPLACE_CMD} -e "s|${LOCAL_SRCDIR}|mail/enigmail${PKGNAMESUFFIX}|g" \
		`${FIND} ${WRKSRC} -name autoconf.mk`

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} export)
	@(cd ${WRKSRC}/modules/libreg; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/string; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/obsolete; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/extensions/ipc; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});
	@(cd ${WRKSRC}/extensions/enigmail; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});

do-install:
	@for f in ${COMPONENTS}; do \
		${INSTALL_DATA} ${WRKSRC}/dist/bin/components/$$f ${LOCAL_PREFIX}/components; \
	done
	@for f in ${CHROME}; do \
		${INSTALL_DATA} ${WRKSRC}/dist/bin/chrome/$$f ${LOCAL_PREFIX}/chrome; \
	done
	@for f in ${PREF}; do \
		${INSTALL_DATA} ${WRKSRC}/dist/bin/defaults/pref/$$f ${LOCAL_PREFIX}/defaults/pref; \
	done

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
