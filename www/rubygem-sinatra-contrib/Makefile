# $FreeBSD$

PORTNAME=	sinatra-contrib
PORTVERSION=	2.0.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of useful Sinatra extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-mustermann>=1.0<2:devel/rubygem-mustermann \
		rubygem-rack-protection>=${PORTVERSION}:www/rubygem-rack-protection \
		rubygem-sinatra>=${PORTVERSION}:www/rubygem-sinatra \
		rubygem-tilt>=2.0<3:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

post-patch:
# Remove backports
	@${REINPLACE_CMD} -e '/backports/d' ${WRKSRC}/${GEMSPEC}
	@${REINPLACE_CMD} -e '/require "backports"/d' ${WRKSRC}/lib/sinatra/*.rb ${WRKSRC}/lib/sinatra/contrib/setup.rb

.include <bsd.port.mk>
