# New ports collection makefile for:   ttftot42
# Date created:        22 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttftot42
PORTVERSION=	0.3.1
CATEGORIES=	print
MASTER_SITES=	http://www.giga.or.at/pub/nih/ttftot42/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType to Type42 font converter

PLIST_FILES=	bin/ttftot42
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CFLAGS=-I${LOCALBASE}/include/freetype1/freetype"

.include <bsd.port.mk>
