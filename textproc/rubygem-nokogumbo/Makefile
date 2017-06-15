# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nokogumbo
PORTVERSION=	1.4.10
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Nokogiri interface to the Gumbo HTML5 parser

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml

USE_RUBY=	yes
USES=		gem pkgconfig

.include <bsd.port.mk>
