# New ports collection makefile for:	freetype
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freetype
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,freetype,} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/%SUBDIR%/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/%SUBDIR%/ \
		http://ftp.sunet.se/pub/text-processing/freetype/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	freetype1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free and portable TrueType font rendering engine

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

.ifdef USE_FREETYPE
.error You have `USE_FREETYPE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

# Older versions of freetype installed include files in ${PREFIX}/include
# this is a compatibility hack for now

#post-install:
#	${LN} -fs ${PREFIX}/include/freetype/*.h ${PREFIX}/include

.include <bsd.port.mk>
