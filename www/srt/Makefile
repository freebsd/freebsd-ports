PORTNAME=	srt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure Reliable Transport (SRT) Protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++11-lang shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Haivision

SHEBANG_FILES=	scripts/srt-ffplay

CMAKE_TESTING_ON=	ENABLE_TESTING ENABLE_UNITTESTS # test TestIPv6.v6_calls_v4 hangs: https://github.com/Haivision/srt/issues/2007

.include <bsd.port.mk>
