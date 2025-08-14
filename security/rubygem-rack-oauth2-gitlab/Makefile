PORTNAME=	rack-oauth2
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OAuth 2.0 Server & Client Library
WWW=		https://github.com/nov/rack-oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=0:devel/rubygem-activesupport-gitlab \
		rubygem-attr_required>=0:devel/rubygem-attr_required \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0:www/rubygem-faraday-follow_redirects-gitlab \
		rubygem-json-jwt-gitlab>=1.11.0:www/rubygem-json-jwt-gitlab \
		rubygem-rack>=2.1.0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
