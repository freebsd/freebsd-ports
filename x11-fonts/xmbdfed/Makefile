# New ports collection makefile for:	xmbdfed
# Date created:		June 20, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	xmbdfed
PORTVERSION=	4.7.1
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://crl.nmsu.edu/~mleisher/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-patch1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif tool for editing X11 bitmap fonts

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_MOTIF=	yes

MAN1=		xmbdfed.1
PLIST_FILES=	bin/xmbdfed

.include <bsd.port.mk>
