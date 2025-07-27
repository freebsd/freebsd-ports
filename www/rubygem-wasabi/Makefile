PORTNAME=	wasabi
PORTVERSION=	5.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Library for simple WSDL parsing
WWW=		https://github.com/savonrb/wasabi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>0:www/rubygem-addressable \
		rubygem-faraday>=1.9:www/rubygem-faraday \
		rubygem-nokogiri>=1.13.9:textproc/rubygem-nokogiri

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
