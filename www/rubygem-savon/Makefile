# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	savon
PORTVERSION=	2.11.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for SOAP communications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-akami>=1.2:www/rubygem-akami \
		rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-gyoku>=1.2:devel/rubygem-gyoku \
		rubygem-httpi>=2.3:www/rubygem-httpi \
		rubygem-nokogiri>=1.4.0:textproc/rubygem-nokogiri \
		rubygem-nori>=2.4:devel/rubygem-nori \
		rubygem-wasabi>=3.4:www/rubygem-wasabi

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
