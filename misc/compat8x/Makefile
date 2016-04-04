# $FreeBSD$

PORTNAME=	compat8x
PORTVERSION=	8.4.804000.20151116
CATEGORIES=	misc
MASTER_SITES=	LOCAL/des
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Convenience package to install the compat8x libraries

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		is for FreeBSD 8.x and newer
.endif

.if ${OSVERSION} >= 1000000
RUN_DEPENDS=	compat9x-${ARCH}>=0:misc/compat9x
.endif

.if ${ARCH} == amd64
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
