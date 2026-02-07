PORTNAME=	redis-rack
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Redis Store for Rack
WWW=		https://redis-store.org/redis-rack/ \
		https://github.com/redis-store/redis-rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack-session10>=0.2.0:www/rubygem-rack-session10 \
		rubygem-redis-store-gitlab>=1.2<2:devel/rubygem-redis-store-gitlab

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/appraisal ${STAGEDIR}${PREFIX}/bin/rake

.include <bsd.port.mk>
