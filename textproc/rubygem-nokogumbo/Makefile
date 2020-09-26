# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nokogumbo
PORTVERSION=	2.0.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Nokogiri interface to the Gumbo HTML5 parser

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nokogiri>=1.8.4<2:textproc/rubygem-nokogiri

USES=		gem gnome pkgconfig
USE_GNOME=	libxml2
USE_RUBY=	yes

.include <bsd.port.mk>
