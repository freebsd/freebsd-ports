# New ports collection makefile for:    xfed
# Version required:     something old
# Date created:         7 December 1994
# Whom:                 asami
#
# $FreeBSD$
#

DISTNAME=	xfed
PKGNAME=	xfed-1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/graphics/systems/X11.old/pub/R6untarred/contrib/programs/

MAINTAINER=	ports@FreeBSD.org

IGNOREFILES=	${DISTFILES}
USE_IMAKE=	yes
MAKE_FLAGS=	MANDIR=${PREFIX}/man/man1 BINDIR=${PREFIX}/bin -f
WRKSRC=		${WRKDIR}/xfed
MAN1=		xfed.1

.include <bsd.port.mk>
