# Created by: hrs, lesi
# $FreeBSD$

# NOTE: libc.so.5 is built with _PATH_LOCALE defined to
# "/usr/local/share/compat/locale" in src/include/paths.h so data installed by
# misc/localedata works out of the box if installed in default PREFIX.

PORTNAME=	compat5x
PORTVERSION=	5.4.0.8.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	LOCAL/amdmi3/compat5x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convenience package to install the compat5x libraries

RUN_DEPENDS=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:misc/localedata

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=	tar:bzip2
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386 sparc64
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: fails to link lib/compat/libpthread.so.1
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
USE_LDCONFIG32=	${TARGET32_DIR}
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	${RM} -f ${WRKSRC}/libpthread.so.1
	(cd ${STAGEDIR}${TARGET_DIR} && ${LN} -sf libthr.so.1 libpthread.so.1)
	(cd ${WRKSRC} && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	${RM} -f ${WRKSRC}/lib32/libpthread.so.1
	(cd ${STAGEDIR}${TARGET32_DIR} && ${LN} -sf libthr.so.1 libpthread.so.1)
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
