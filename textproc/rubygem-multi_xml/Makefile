# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multi_xml
PORTVERSION=	0.6.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library provide swappable XML backends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

OPTIONS_DEFINE=	NOKOGIRI
NOKOGIRI_DESC=	Use Nokogiri for parsing

NOKOGIRI_RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

.include <bsd.port.mk>
