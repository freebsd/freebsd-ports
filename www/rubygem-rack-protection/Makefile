PORTNAME=	rack-protection
PORTVERSION=	4.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of Rack middleware to protect against opportunistic attack
WWW=		https://sinatrarb.com/protection/ \
		https://github.com/sinatra/sinatra/tree/main/rack-protection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	rubygem-base64>=0.1.0:converters/rubygem-base64 \
		rubygem-logger>=1.6.0:devel/rubygem-logger \
		rubygem-rack>=3.0.0,3<4,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
