# $FreeBSD$

PORTNAME=	json-jwt
PORTVERSION=	1.7.2
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-bindata>=0:devel/rubygem-bindata \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-securecompare>=0:security/rubygem-securecompare \
		rubygem-url_safe_base64>=0:converters/rubygem-url_safe_base64

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
