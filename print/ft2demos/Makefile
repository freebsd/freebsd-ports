# New ports collection makefile for:	ft2demos
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ft2demos
PORTVERSION=	2.0.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,freetype,} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/%SUBDIR%/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/%SUBDIR%/ \
		http://ftp.sunet.se/pub/text-processing/freetype/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	freetype2

MAINTAINER=	kanou@mil.allnet.ne.jp

BUILD_DEPENDS+=	libtool:${PORTSDIR}/devel/libtool
BUILD_DEPENDS+=	${FREETYPE_WRKSRC}/config.mk:${PORTSDIR}/print/freetype2:build
LIB_DEPENDS=	freetype.8:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	TOP="${FREETYPE_WRKSRC}"

.include <bsd.port.pre.mk>

FREETYPE_WRKSRC!=	cd ${PORTSDIR}/print/freetype2; ${MAKE} -V WRKSRC

FT_PROGRAMS=	ftdump ftlint ftmulti ftstring fttimer ftview ftmemchk

do-install:
	@(cd ${WRKSRC}/bin/.libs/ ; ${INSTALL_PROGRAM} ${FT_PROGRAMS} ${PREFIX}/bin)

.include <bsd.port.post.mk>
