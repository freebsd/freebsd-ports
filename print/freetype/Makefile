# Created by: jseger@FreeBSD.org
# $FreeBSD$

PORTNAME=	freetype
PORTVERSION=	1.3.1
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	SF \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype1/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype1/ \
		ftp://ftp.freetype.org/freetype/freetupe1/

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Free and portable TrueType font rendering engine

USES=		cpe desthack libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
