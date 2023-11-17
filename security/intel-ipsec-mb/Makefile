PORTNAME=	intel-ipsec-mb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	security

PATCH_SITES=	https://github.com/intel/${PORTNAME}/commit/
PATCHFILES=	c266eb633019bf0eef2c9df1ce814f22b9ee2d51.patch:-p1

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Intel(R) Multi-Buffer Crypto for IPsec Library
WWW=		https://github.com/intel/intel-ipsec-mb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

TEST_TARGET=	test

PLIST_FILES=	include/intel-ipsec-mb.h \
		lib/libIPSec_MB.so \
		lib/libIPSec_MB.so.1 \
		lib/libIPSec_MB.so.${DISTVERSION}.0 \
		man/man7/libipsec-mb-dev.7.gz \
		man/man7/libipsec-mb.7.gz

OPTIONS_DEFINE=	AESNIEMU

AESNIEMU_DESC=	Enable AESI-NI Emulation

AESNIEMU_CMAKE_BOOL=    AESNI_EMU

.include <bsd.port.mk>
