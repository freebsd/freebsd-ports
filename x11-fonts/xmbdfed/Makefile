# New ports collection makefile for:	xmbdfed
# Version required:	3.4
# Date created:		June 20, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

DISTNAME=	xmbdfed-3.9
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://crl.nmsu.edu/CLR/multiling/General/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	xmbdfed-3.9.patch1 xmbdfed-3.9.patch2

MAINTAINER=	jfieber@FreeBSD.ORG

.if defined(USE_FREETYPE)
LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype
.endif

USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes

MAN1=		xmbdfed.1

.if !defined(USE_FREETYPE)
pre-extract:
	@${ECHO} "You can add the optional FreeType import capability by defining USE_FREETYPE"
.endif

.include <bsd.port.mk>
