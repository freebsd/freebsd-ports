PORTNAME=	rackup
DISTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-rack>=3,3:www/rubygem-rack \
		rubygem-webrick>0:www/rubygem-webrick

USES=		gem

PLIST_FILES=	bin/rackup

.include <bsd.port.mk>
