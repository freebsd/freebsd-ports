# New ports collection makefile for:	xmbdfed
# Version required:	4.3.3
# Date created:		June 20, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

DISTNAME=	xmbdfed-4.3
PKGNAME=	xmbdfed-4.3.3
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://crl.nmsu.edu/CLR/multiling/General/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.patch1 ${DISTNAME}.patch2 ${DISTNAME}.patch3

MAINTAINER=	ports@FreeBSD.org

.if defined(USE_FREETYPE)
LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype
.endif

USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes

MAN1=		xmbdfed.1

.if !defined(USE_FREETYPE)
pre-extract:
	@${ECHO_MSG} "You can add the optional FreeType import capability by defining USE_FREETYPE"
.endif

.include <bsd.port.mk>
