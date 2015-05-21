# $FreeBSD$

PORTNAME=	compat10x
PORTVERSION=	10.0.1000510.201410
CATEGORIES=	misc
MASTER_SITES=	LOCAL/garga/compat
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Convenience package to install the compat10x libraries

LICENSE=	BSD2CLAUSE

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		is for FreeBSD 10.x and newer
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
