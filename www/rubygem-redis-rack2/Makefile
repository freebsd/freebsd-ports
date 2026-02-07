PORTNAME=	redis-rack
PORTVERSION=	2.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis Store for Rack
WWW=		https://redis-store.org/redis-rack/ \
		https://github.com/redis-store/redis-rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack22>=2.0.8,3<3,3:www/rubygem-rack22 \
		rubygem-redis-store>=1.2<2:devel/rubygem-redis-store

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/appraisal ${STAGEDIR}${PREFIX}/bin/rake

.include <bsd.port.mk>
