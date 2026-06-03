PORTNAME=	rackup
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-rack-gitlab>=2.2<3:www/rubygem-rack-gitlab \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
