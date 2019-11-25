# $FreeBSD$

PORTNAME=	riemann-client
DISTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Client for the distributed event system Riemann

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-beefcake>=1.2:net/rubygem-beefcake \
		rubygem-mtrc>=0.0.4:math/rubygem-mtrc \
		rubygem-trollop>=2.9:devel/rubygem-trollop

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
