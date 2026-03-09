PORTNAME=	chef-utils
PORTVERSION=	18.9.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	18

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Basic utility functions for Core Chef Infra development
WWW=		https://github.com/chef/chef/tree/main/chef-utils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^18\.

.include <bsd.port.mk>
