# New ports collection makefile for:    xfed
# Version required:     something old
# Date created:         7 December 1994
# Whom:                 asami
#
# $Id: Makefile,v 1.16 1997/12/25 22:29:52 asami Exp $
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

pre-clean:
	-rm -rf ${.CURDIR}/src

.include <bsd.port.mk>
