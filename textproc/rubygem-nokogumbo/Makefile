PORTNAME=	nokogumbo
PORTVERSION=	2.0.5
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Nokogiri interface to the Gumbo HTML5 parser
WWW=		https://github.com/rubys/nokogumbo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Upstream has merged into textproc/rubygem-nokogiri
EXPIRATION_DATE=	2025-03-31
BROKEN=		Build fails with all supported Ruby versions

RUN_DEPENDS=	rubygem-nokogiri>=1.8.4<2:textproc/rubygem-nokogiri

USES=		gem gnome pkgconfig
USE_GNOME=	libxml2

.include <bsd.port.mk>
