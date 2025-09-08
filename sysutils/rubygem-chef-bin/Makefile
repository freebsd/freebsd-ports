PORTNAME=	chef-bin
PORTVERSION=	18.8.11
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chef-branded binstubs for chef-client
WWW=		https://github.com/chef/chef/tree/main/chef-bin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/chef-apply \
		bin/chef-client \
		bin/chef-resource-inspector \
		bin/chef-service-manager \
		bin/chef-shell \
		bin/chef-solo \
		bin/chef-windows-service

.include <bsd.port.mk>
