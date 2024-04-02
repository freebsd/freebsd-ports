PORTNAME=	rackup
DISTVERSION=	2.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-rack>=3,3:www/rubygem-rack \
		rubygem-webrick>=1.8<2:www/rubygem-webrick

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rackup

.include <bsd.port.mk>
