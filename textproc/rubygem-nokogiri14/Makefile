# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.4.7
PORTREVISION=	1
PKGNAMESUFFIX=	14
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT

USE_RUBY=	yes
USES=		gem pkgconfig
USE_GNOME=	libxml2 libxslt
CONFIGURE_ARGS=	--use-system-libraries

PLIST_FILES=	bin/nokogiri14

PORTSCOUT=	limit:^1\.4

post-patch:
	@${MV} ${WRKSRC}/bin/nokogiri ${WRKSRC}/bin/nokogiri14
	@${RM} ${WRKSRC}/bin/nokogiri.orig

.include <bsd.port.mk>
