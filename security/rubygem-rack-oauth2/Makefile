# $FreeBSD$

PORTNAME=	rack-oauth2
PORTVERSION=	1.16.0
PORTREVISION=	0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OAuth 2.0 Server & Client Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-attr_required>=0:devel/rubygem-attr_required \
		rubygem-httpclient>=0:www/rubygem-httpclient \
		rubygem-json-jwt>=1.11.0:www/rubygem-json-jwt \
		rubygem-rack>=2.1.0:www/rubygem-rack

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
