# New ports collection makefile for:	freetype
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freetype
PORTVERSION=	1.3.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype1/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype1/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype1/ \
		ftp://ring.aist.go.jp/pub/graphics/freetype/freetype1/ \
		ftp://ring.asahi-net.or.jp/pub/graphics/freetype/ \
		ftp://ring.nacsis.ac.jp/pub/graphics/freetype/ \
		ftp://ring.so-net.ne.jp/pub/graphics/freetype/ \
		ftp://ftp.freetype.org/pub/freetype1/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jseger@FreeBSD.org

USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

# Older versions of freetype installed include files in ${PREFIX}/include
# this is a compatibility hack for now

post-install:
	${LN} -fs ${PREFIX}/include/freetype/*.h ${PREFIX}/include

.include <bsd.port.mk>
