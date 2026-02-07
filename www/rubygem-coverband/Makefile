PORTNAME=	coverband
PORTVERSION=	6.1.5
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rack middleware to measure production code usage
WWW=		https://github.com/danmayer/coverband

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-redis-gitlab>=3.0:databases/rubygem-redis-gitlab

USES=		gem shebangfix

SHEBANG_FILES=	lua/install.sh

NO_ARCH=	yes

.include <bsd.port.mk>
