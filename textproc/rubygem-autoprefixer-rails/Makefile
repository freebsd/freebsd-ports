# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autoprefixer-rails
PORTVERSION=	6.0.3
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse CSS and add vendor prefixes to CSS rules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-execjs>=0:${PORTSDIR}/devel/rubygem-execjs \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
