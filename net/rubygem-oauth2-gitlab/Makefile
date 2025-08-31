PORTNAME=	oauth2
PORTVERSION=	2.0.13
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby wrapper for the OAuth 2.0 protocol
WWW=		https://github.com/oauth-xx/oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday-gitlab>=0.17.3<4:www/rubygem-faraday-gitlab \
		rubygem-jwt>=1.0<4:www/rubygem-jwt \
		rubygem-logger-gitlab>=1.2<2:devel/rubygem-logger-gitlab \
		rubygem-multi_xml>=0.5<1:textproc/rubygem-multi_xml \
		rubygem-rack>=1.2,3<4,3:www/rubygem-rack \
		rubygem-snaky_hash>=2.0.3<3:devel/rubygem-snaky_hash \
		rubygem-version_gem>=1.1.8<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
