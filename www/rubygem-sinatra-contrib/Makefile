PORTNAME=	sinatra-contrib
PORTVERSION=	4.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions
WWW=		https://sinatrarb.com/contrib/ \
		https://github.com/sinatra/sinatra

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0.0.2:devel/rubygem-multi_json \
		rubygem-mustermann>=3.0<4:devel/rubygem-mustermann \
		rubygem-rack-protection>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-rack-protection \
		rubygem-sinatra>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-sinatra \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
