# New ports collection makefile for:	aspell
# Version required:	0.29.1
# Date created:		7 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	aspell-.29.1
PKGNAME=	aspell-0.29.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.sourceforge.net/aspell/

MAINTAINER=	ade@FreeBSD.org

USE_NEWGCC=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS} -I${WRKSRC}"
USE_GMAKE=	yes
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}

.include <bsd.port.mk>
