PORTNAME=	libxcoder
DISTVERSIONPREFIX=	v
DISTVERSION=	5.9.0
CATEGORIES=	multimedia

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Userland library and tools for NETINT Quadra video processing units
WWW=		https://github.com/NETINT-Technologies/netint_libxcoder

LICENSE=	MIT0
LICENSE_NAME=	MIT No Attribution
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	NETINT supports Quadra cards only on these architectures
IGNORE_FreeBSD_14=	needs the Linux-compatible ioctls of nvme(4), added in FreeBSD 15.0

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	NETINT-Technologies
GH_PROJECT=	netint_libxcoder
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}

PLIST_SUB=	XCODER_REV=${XCODER_REV}

XCODER_REV=	5906tFr1

post-patch:
# configure creates the install directories in the live PREFIX
	@${REINPLACE_CMD} -e '/^# Attempt to create dir/,/^echo .configure ok/{/^echo/!d;}' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/pkgconfig|$${LIBDIR}/../libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

post-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/build/nvmefw ${FILESDIR}/nvmefw.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/nvmefw ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/quadra_fw_upgrade.sh \
		${STAGEDIR}${PREFIX}/sbin/quadra_fw_upgrade
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/libxcoder.so.${XCODER_REV}

.include <bsd.port.mk>
