# New ports collection makefile for:	ft2demos
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	ft2demos
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,freetype,} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/%SUBDIR%/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/%SUBDIR%/ \
		http://ftp.sunet.se/pub/text-processing/freetype/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	freetype2

MAINTAINER=	kanou@khdd.net
COMMENT=	Demo programs for FreeType2

BUILD_DEPENDS+=	${FREETYPE_WRKSRC}/config.mk:${PORTSDIR}/print/freetype2:build
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	TOP_DIR="${FREETYPE_WRKSRC}"

.include <bsd.port.pre.mk>

FREETYPE_WRKSRC!=	cd ${PORTSDIR}/print/freetype2; ${MAKE} -V WRKSRC

FT_PROGRAMS=	ftbench ftdump ftlint ftmemchk ftmulti ftstring fttimer ftview testname

do-install:
	@(cd ${WRKSRC}/bin/.libs/; ${INSTALL_PROGRAM} ${FT_PROGRAMS} ${PREFIX}/bin)

.include <bsd.port.post.mk>
