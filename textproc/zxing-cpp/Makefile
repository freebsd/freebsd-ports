# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zxing-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ZXing C++ Library for QR code recognition

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang iconv
USE_GITHUB=	yes
GH_ACCOUNT=	nu-book
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
