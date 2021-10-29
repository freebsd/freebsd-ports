# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	fastops
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	AVX/AVX2-accelerated bulk call of math functions

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses AVX and AVX2 instructions

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	yandex

.include <bsd.port.mk>
