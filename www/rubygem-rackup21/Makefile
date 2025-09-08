PORTNAME=	rackup
PORTVERSION=	2.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	21

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	General server command for Rack applications
WWW=		https://github.com/rack/rackup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

DEPRECATED=	No consumers in ports tree
EXPIRATION_DATE=	2025-09-30

RUN_DEPENDS=	rubygem-rack>=3,3:www/rubygem-rack \
		rubygem-webrick>=1.8<2:www/rubygem-webrick

USES=		gem

CONFLICTS_INSTALL=	rubygem-rackup # bin/rackup

NO_ARCH=	yes
PORTSCOUT=	limit:^2\.1\.

PLIST_FILES=	bin/rackup

.include <bsd.port.mk>
