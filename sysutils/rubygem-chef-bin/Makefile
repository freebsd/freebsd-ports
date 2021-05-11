# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	chef-bin
PORTVERSION=	16.13.16
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chef-branded binstubs for chef-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef>=${PORTVERSION}:sysutils/rubygem-chef

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/chef-apply \
		bin/chef-client \
		bin/chef-resource-inspector \
		bin/chef-service-manager \
		bin/chef-shell \
		bin/chef-solo \
		bin/chef-windows-service

.include <bsd.port.mk>
