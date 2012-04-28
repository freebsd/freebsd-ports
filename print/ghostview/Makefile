# New ports collection makefile for:	ghostview
# Date created:		21 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	ghostview
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://ftp.gnu.org/old-gnu/ghostview/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/ghostview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 front-end for ghostscript, the GNU postscript previewer

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_IMAKE=	yes
USE_XORG=	xbitmaps xaw
USE_GHOSTSCRIPT_RUN=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		ghostview.1

CFLAGS+=	-DUSG

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
