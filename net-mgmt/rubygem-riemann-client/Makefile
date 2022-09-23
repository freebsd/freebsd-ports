PORTNAME=	riemann-client
DISTVERSION=	1.0.1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Client for the distributed event system Riemann
WWW=		https://github.com/riemann/riemann-ruby-client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-beefcake>=1.2:net/rubygem-beefcake \
		rubygem-mtrc>=0.0.4:math/rubygem-mtrc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
