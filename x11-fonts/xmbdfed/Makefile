# New ports collection makefile for:	xmbdfed
# Date created:		June 20, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	xmbdfed
PORTVERSION=	4.5.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://crl.nmsu.edu/~mleisher/ \
		ftp://crl.nmsu.edu/CLR/multiling/General/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION:R}-patch1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif tool for editing X11 bitmap fonts

USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_MOTIF=	yes

MAN1=		xmbdfed.1
PLIST_FILES=	bin/xmbdfed

.include <bsd.port.mk>
