PORTNAME=	SoapySDR
DISTVERSIONPREFIX=	soapy-sdr-
DISTVERSION=	0.9.0
CATEGORIES=	misc hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vendor and platform neutral SDR support library
WWW=		https://github.com/pothosware/SoapySDR

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake compiler:c++11-lang lua:53 luajit
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/pothosware/SoapySDR/issues/479

LDFLAGS+=	-pthread

.include <bsd.port.mk>
