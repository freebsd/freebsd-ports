# New ports collection makefile for:	aspell
# Date created:		7 December 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION= 	0.29.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.sourceforge.net/aspell/
DISTNAME=	${PORTNAME}-.29.1

MAINTAINER=	ade@FreeBSD.org

USE_NEWGCC=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS} -I${WRKSRC}"
USE_GMAKE=	yes
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}

.include <bsd.port.mk>
