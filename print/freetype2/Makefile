# New ports collection makefile for:	freetype
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freetype2
PORTVERSION=	2.0
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
MASTER_SITE_SUBDIR=	${PORTNAME:S/2//}
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	jseger@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix
LIBTOOLFILES=	${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

.include <bsd.port.mk>
