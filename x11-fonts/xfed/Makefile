# New ports collection makefile for:    xfed
# Version required:     something old
# Date created:         7 December 1994
# Whom:                 asami
#
# $Id: Makefile,v 1.17 1998/08/07 22:43:10 asami Exp $
#

DISTNAME=	xfed
PKGNAME=	xfed-1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/graphics/systems/X11.old/pub/R6untarred/contrib/programs/

MAINTAINER=	ports@FreeBSD.ORG

IGNOREFILES=	${DISTFILES}
USE_IMAKE=	yes
MAKE_FLAGS=	MANDIR=${PREFIX}/man/man1 BINDIR=${PREFIX}/bin -f
WRKSRC=		${WRKDIR}/pub/graphics/systems/X11.old/pub/R6untarred/contrib/programs/xfed
MAN1=		xfed.1

pre-clean:
	-rm -rf ${.CURDIR}/src

.include <bsd.port.mk>
