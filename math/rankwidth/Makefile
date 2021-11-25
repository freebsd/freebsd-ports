# Created by: thierry@pompo.net

PORTNAME=	rankwidth	# Also known as: rw
PORTVERSION=	0.9
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	rw-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Calculation of rank-width and rank-decompositions

LICENSE=	GPLv2

LIB_DEPENDS=	libigraph.so:math/igraph

USES=		autoreconf libtool localbase pkgconfig

CONFLICTS_INSTALL=	rw

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/rw

.include <bsd.port.mk>
