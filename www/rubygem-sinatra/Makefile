# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classy web development framework in ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mustermann>=1.0:devel/rubygem-mustermann \
		rubygem-rack>=2.0:www/rubygem-rack \
		rubygem-rack-protection>=2.0.0:www/rubygem-rack-protection \
		rubygem-tilt>=2.0:devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
