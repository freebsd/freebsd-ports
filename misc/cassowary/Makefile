# New ports collection makefile for:   cassowary
# Version required:    0.52
# Date created:        01 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD>org>
#
# $FreeBSD$
#

DISTNAME=	cassowary-0.52
CATEGORIES=	misc
MASTER_SITES=	http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	GTL.3:${PORTSDIR}/misc/gtl

BROKEN=		build

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

post-configure:
	${MKDIR} ${WRKSRC}/c++/cassowary
	${CP} ${WRKSRC}/c++/*.h ${WRKSRC}/c++/cassowary/

.include <bsd.port.mk>
