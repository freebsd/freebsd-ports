# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	savon
PORTVERSION=	0.9.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Library for SOAP communications

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-nori>=1.0.3:devel/rubygem-nori \
		rubygem-httpi>=0.9.0:www/rubygem-httpi \
		rubygem-wasabi>=1.0.0:www/rubygem-wasabi \
		rubygem-akami>=1.0.0:www/rubygem-akami \
		rubygem-gyoku>=0.4.6:devel/rubygem-gyoku \
		rubygem-nokogiri>=1.6.1:textproc/rubygem-nokogiri

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
