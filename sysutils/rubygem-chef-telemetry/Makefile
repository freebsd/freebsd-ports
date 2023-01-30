PORTNAME=	chef-telemetry
PORTVERSION=	1.1.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Send user actions to the Chef telemetry system
WWW=		https://github.com/chef/chef-telemetry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config>=0:sysutils/rubygem-chef-config \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
