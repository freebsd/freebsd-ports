# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	oauth2
PORTVERSION=	2.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for the OAuth 2.0 protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=0.17.3<3.0:www/rubygem-faraday \
		rubygem-jwt>=1.0<3.0:www/rubygem-jwt \
		rubygem-multi_xml>=0.5<1:textproc/rubygem-multi_xml \
		rubygem-rack>=1.2,3<3,3:www/rubygem-rack \
		rubygem-rash_alt>=0.4<1:devel/rubygem-rash_alt \
		rubygem-version_gem>=1.0<2:devel/rubygem-version_gem

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
