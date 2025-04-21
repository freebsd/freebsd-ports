PORTNAME=	rackup
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	10

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-rack22>=2.2,3<3,3:www/rubygem-rack22 \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		gem

NO_ARCH=	yes
PORTSCOUT=	limit:^1\.0\.

.include <bsd.port.mk>
