# Created by: Michael Moll <kvedulv@kvedulv.de>

PORTNAME=	chef-api
PORTVERSION=	0.10.10
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Lightweight Chef API client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	The chef-api gem is no longer maintained. Please use the supported Chef::ServerAPI library from the Chef gem
EXPIRATION_DATE=2021-12-31

RUN_DEPENDS=	rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-mixlib-log>=1<4:devel/rubygem-mixlib-log

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
