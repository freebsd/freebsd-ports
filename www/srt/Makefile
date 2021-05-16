PORTNAME=	srt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure Reliable Transport (SRT) Protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Haivision

SHEBANG_FILES=	scripts/srt-ffplay

.include <bsd.port.mk>
