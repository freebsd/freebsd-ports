PORTNAME=	rankwidth	# Also known as: rw
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	rw-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Calculation of rank-width and rank-decompositions
WWW=		https://sourceforge.net/projects/rankwidth/

LICENSE=	GPLv2

# See https://sourceforge.net/p/rankwidth/tickets/4/
BROKEN=		does not support igraph>=1.0.0

LIB_DEPENDS=	libigraph.so:math/igraph

USES=		autoreconf libtool localbase pkgconfig

CONFLICTS_INSTALL=	rw

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/rw

.include <bsd.port.mk>
