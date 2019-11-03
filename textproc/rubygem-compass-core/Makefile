# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compass-core
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compass core stylesheet library and minimum required ruby extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-multi_json>=1.0<2:devel/rubygem-multi_json \
		rubygem-sass34>=3.3.0<3.5:textproc/rubygem-sass34

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
