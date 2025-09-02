PORTNAME=	acme-client
PORTVERSION=	2.0.23
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client for the ACME protocol
WWW=		https://github.com/unixcharles/acme-client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-faraday>=1.0<3.0.0:www/rubygem-faraday \
		rubygem-faraday-retry>=1.0<3.0.0:www/rubygem-faraday-retry

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>
