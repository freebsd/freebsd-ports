# $FreeBSD$

PORTNAME=	rack-oauth2
PORTVERSION=	1.2.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OAuth 2.0 Server & Client Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=2.3:devel/rubygem-activesupport4 \
		rubygem-attr_required>=0.0.5:devel/rubygem-attr_required \
		rubygem-httpclient>=2.4:www/rubygem-httpclient \
		rubygem-multi_json>=1.3.6:devel/rubygem-multi_json \
		rubygem-rack16>=1.1:www/rubygem-rack16

PORTSCOUT=	limit:^1\.2\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
