PORTNAME=	asana
PORTVERSION=	2.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for the Asana REST API
WWW=		https://github.com/Asana/ruby-asana

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0:www/rubygem-faraday-follow_redirects \
		rubygem-faraday-multipart>=0:www/rubygem-faraday-multipart \
		rubygem-oauth2>=1.4<3:net/rubygem-oauth2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
