PORTNAME=	intel-ipsec-mb
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	security

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Intel(R) Multi-Buffer Crypto for IPsec Library
WWW=		https://github.com/intel/intel-ipsec-mb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/share/man/man7

PLIST_FILES=	include/intel-ipsec-mb.h \
		lib/libIPSec_MB.so \
		lib/libIPSec_MB.so.2 \
		lib/libIPSec_MB.so.${DISTVERSION}.0 \
		share/man/man7/libipsec-mb-dev.7.gz \
		share/man/man7/libipsec-mb.7.gz

CMAKE_TESTING_OFF=	BUILD_LIBRARY_ONLY
CMAKE_ON=	BUILD_LIBRARY_ONLY

OPTIONS_DEFINE=	AESNIEMU

AESNIEMU_DESC=	Enable AESI-NI Emulation

AESNIEMU_CMAKE_BOOL=    AESNI_EMU

.include <bsd.port.mk>
