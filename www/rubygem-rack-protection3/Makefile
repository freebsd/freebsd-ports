PORTNAME=	rack-protection
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Collection of Rack middleware to protect against opportunistic attack
WWW=		https://sinatrarb.com/protection/ \
		https://github.com/sinatra/sinatra/tree/main/rack-protection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	rubygem-base64>=0.1.0:converters/rubygem-base64 \
		rubygem-rack22>=2.2.4,3<3,3:www/rubygem-rack22

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
