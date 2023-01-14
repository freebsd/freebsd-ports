PORTNAME=	sinatra-contrib
PORTVERSION=	2.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions
WWW=		https://github.com/sinatra/sinatra-contrib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-mustermann>=2.0:devel/rubygem-mustermann \
		rubygem-rack-protection2>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-rack-protection2 \
		rubygem-sinatra2>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-sinatra2 \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
