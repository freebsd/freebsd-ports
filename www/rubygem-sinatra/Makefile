# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	2.0.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Classy web development framework in ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=1.0:devel/rubygem-mustermann \
		rubygem-rack>=2.0:www/rubygem-rack \
		rubygem-rack-protection>=${PORTVERSION}:www/rubygem-rack-protection \
		rubygem-tilt>=2.0:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
