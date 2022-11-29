PORTNAME=	rackup
DISTVERSION=	0.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rack>=3.0.0.beta1,3:www/rubygem-rack \
		rubygem-webrick>0:www/rubygem-webrick

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/rackup

.include <bsd.port.mk>
