# $FreeBSD$

PORTNAME=	chosen-rails
PORTVERSION=	1.4.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Box enhancer for jQuery and Protoype

LICENSE=	MIT

RUN_DEPENDS=	rubygem-coffee-rails4>=3.2:${PORTSDIR}/devel/rubygem-coffee-rails4 \
		rubygem-compass-rails>=2.0.4:${PORTSDIR}/textproc/rubygem-compass-rails \
		rubygem-railties4>=3.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-sass-rails5>=3.2:${PORTSDIR}/textproc/rubygem-sass-rails5

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
