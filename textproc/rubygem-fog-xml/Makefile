# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-xml
PORTVERSION=	0.1.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extraction of the XML parsing tools shared among 'fog' providers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-nokogiri>=1.5.11<2.0.0:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
