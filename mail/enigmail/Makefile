# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enigmail
PORTVERSION=	0.83.2
PORTREVISION=	0
CATEGORIES=	mail security
MASTER_SITES=	http://mozdev.secsup.org/enigmail/src/ \
		http://downloads.us-east3.mozdev.org/enigmail/src/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.2//}.latest${EXTRACT_SUFX} \
		ipc-1.0.5${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	A GnuPG extension for the Mozilla mail client

EXTRACT_DEPENDS?=	${LOCAL_SRCDIR}/work/mozilla/Makefile:${LOCAL_SRCDIR}:configure
RUN_DEPENDS?=	mozilla:${LOCAL_SRCDIR}

USE_X_PREFIX=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mozilla
LOCAL_SRCDIR?=	${PORTSDIR}/www/mozilla
LOCAL_SUBDIR?=	lib/mozilla
LOCAL_PREFIX=	${PREFIX}/${LOCAL_SUBDIR}

COMPONENTS=	ipc.xpt enigmime.xpt libenigmime.so enigmail.xpt enigmail.js enigprefs-service.js
CHROME=		enigmail.jar enigmail-skin.jar enigmail-skin-tbird.jar

PLIST_SUB=	LOCAL_SUBDIR=${LOCAL_SUBDIR}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${LOCAL_SRCDIR}/work/mozilla ${WRKSRC}
	@for file in ${EXTRACT_ONLY}; do \
		cd ${WRKSRC}/extensions && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}; \
	done

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} export)
	@(cd ${WRKSRC}/modules/libreg; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/string; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/obsolete; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/extensions/ipc; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});
	@(cd ${WRKSRC}/extensions/enigmail; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});

do-install:
	@for file in ${COMPONENTS}; do \
		${INSTALL_DATA} ${WRKSRC}/dist/bin/components/$$file ${LOCAL_PREFIX}/components; \
	done
	@for file in ${CHROME}; do \
		${INSTALL_DATA} ${WRKSRC}/dist/bin/chrome/$$file ${LOCAL_PREFIX}/chrome; \
	done

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
