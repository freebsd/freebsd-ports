# New ports collection makefile for:	ft2demos
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ft2demos
PORTVERSION=	2.0.2
CATEGORIES=	print
MASTER_SITES=	ftp://freetype.sourceforge.net/pub/freetype/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,freetype,} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/%SUBDIR%/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/%SUBDIR%/ \
		http://ftp.sunet.se/pub/text-processing/freetype/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	freetype2

MAINTAINER=	kanou@mil.allnet.ne.jp

BUILD_DEPENDS+=	${PORTSDIR}/print/freetype2/work/freetype-${PORTVERSION}/config.mk:${PORTSDIR}/print/freetype2:build
LIB_DEPENDS=	freetype.7:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
MAKE_ENV=	TOP="${PORTSDIR}/print/freetype2/work/freetype-${PORTVERSION}"

FT_PROGRAMS=	ftdump ftlint ftmulti ftstring fttimer ftview

do-install:
	@(cd ${WRKSRC}/bin/.libs/ ; ${INSTALL_PROGRAM} ${FT_PROGRAMS} ${PREFIX}/bin)
	@(cd ${WRKSRC}/bin/.libs/ ; ${INSTALL_PROGRAM} memtest ${PREFIX}/bin/ftmemtest)

.include <bsd.port.mk>
