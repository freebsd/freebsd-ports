PORTNAME=	sinatra-contrib
PORTVERSION=	2.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-mustermann>=2.0<3:devel/rubygem-mustermann \
		rubygem-rack-protection>=${PORTVERSION}:www/rubygem-rack-protection \
		rubygem-sinatra>=${PORTVERSION}:www/rubygem-sinatra \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
