PORTNAME=	rqrcode
PORTVERSION=	2.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for encoding QR Codes
WWW=		https://whomwah.github.io/rqrcode/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-chunky_png>=1.0<2:graphics/rubygem-chunky_png \
		rubygem-rqrcode_core>=1.0<2:www/rubygem-rqrcode_core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
