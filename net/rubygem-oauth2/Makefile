PORTNAME=	oauth2
PORTVERSION=	2.0.18
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for the OAuth 2.0 protocol
WWW=		https://oauth2.galtzo.com/ \
		https://github.com/ruby-oauth/oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0.17.3<4.0:www/rubygem-faraday \
		rubygem-jwt>=1.0<4.0:www/rubygem-jwt \
		rubygem-logger>=1.2<2:devel/rubygem-logger \
		rubygem-multi_xml>=0.5<1:textproc/rubygem-multi_xml \
		rubygem-rack>=1.2,3<4,3:www/rubygem-rack \
		rubygem-snaky_hash>=2.0.3<3:devel/rubygem-snaky_hash \
		rubygem-version_gem>=1.1.9<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
