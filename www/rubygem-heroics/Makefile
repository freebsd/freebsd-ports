PORTNAME=	heroics
PORTVERSION=	0.1.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby HTTP client generator for APIs represented with JSON schema
WWW=		https://github.com/interagent/heroics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-erubis>=2.0<3:www/rubygem-erubis \
		rubygem-excon>=0:devel/rubygem-excon \
		rubygem-moneta>=0:devel/rubygem-moneta \
		rubygem-multi_json>=1.9.2:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/heroics-generate \
		bin/heroku-api

.include <bsd.port.mk>
