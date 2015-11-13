# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compass-core
PORTVERSION=	1.0.3
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compass core stylesheet library and minimum required ruby extensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-sass>=3.3.0:${PORTSDIR}/textproc/rubygem-sass

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
