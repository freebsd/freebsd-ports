# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heroics
PORTVERSION=	0.0.25
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	00

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby HTTP client generator for APIs represented with JSON schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-erubis>=2.0<3:www/rubygem-erubis \
		rubygem-excon>=0:devel/rubygem-excon \
		rubygem-moneta>=0:devel/rubygem-moneta \
		rubygem-multi_json>=1.9.2:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/heroics-generate \
		bin/heroku-api

PORTSCOUT=	limit:^0\.0\.

.include <bsd.port.mk>
