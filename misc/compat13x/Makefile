PORTNAME=	compat13x
PORTVERSION=	13.5.1305000.20250516
CATEGORIES=	misc
MASTER_SITES=	LOCAL/arrowd
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Convenience package to install the compat13x libraries

LICENSE=	BSD2CLAUSE

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	aarch64 amd64 i386
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}
NO_SHLIB_REQUIRES_GLOB=	*:32

COMPAT_LIBS=	libcrypto.so.111 \
		libdialog.so.9 \
		libnv.so.0 \
		libssl.so.111

.include "${.CURDIR}/../compat4x/Makefile.makedist"

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 13
IGNORE=		is for FreeBSD 13.x and newer
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
RUN_DEPENDS+=	compat14x-${ARCH}>=0:misc/compat14x
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
