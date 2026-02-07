PORTNAME=	redis-rack
PORTVERSION=	3.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis Store for Rack
WWW=		https://redis-store.org/redis-rack/ \
		https://github.com/redis-store/redis-rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack-session>=0.2.0:www/rubygem-rack-session \
		rubygem-redis-store>=1.2<2:devel/rubygem-redis-store

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/appraisal ${STAGEDIR}${PREFIX}/bin/rake

.include <bsd.port.mk>
