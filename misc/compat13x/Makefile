PORTNAME=	compat13x
PORTVERSION=	13.5.1305000.20250911
CATEGORIES=	misc
MASTER_SITES=	LOCAL/arrowd
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Convenience package to install the compat13x libraries

LICENSE=	BSD2CLAUSE

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

COMPAT_LIBS=	libcrypto.so.111 \
		libdialog.so.9 \
		libdpv.so.2 \
		libnv.so.0 \
		libssl.so.111

OPTIONS_DEFINE=	COMPAT32
OPTIONS_DEFAULT=COMPAT32
OPTIONS_EXCLUDE_aarch64=COMPAT32
OPTIONS_EXCLUDE_i386=COMPAT32
OPTIONS_EXCLUDE_powerpc=COMPAT32
OPTIONS_EXCLUDE_powerpc64le=COMPAT32
COMPAT32_DESC=	Install 32-bit compat libraries
OPTIONS_SUB=	yes

.include "${.CURDIR}/../compat4x/Makefile.makedist"

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 13
IGNORE=		is for FreeBSD 13.x and newer
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
RUN_DEPENDS+=	compat14x-${ARCH}>=0:misc/compat14x
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT32}
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET_DIR})

do-install-COMPAT32-on:
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET32_DIR})

.include <bsd.port.post.mk>
