PORTNAME=	compat10x
PORTVERSION=	10.4.1004000.20181014
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	LOCAL/des
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Convenience package to install the compat10x libraries

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}
NO_SHLIB_PROVIDES_GLOB= libreadline.so.* libhistory.so.*

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000
RUN_DEPENDS+=	compat11x-${ARCH}>=0:misc/compat11x
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
