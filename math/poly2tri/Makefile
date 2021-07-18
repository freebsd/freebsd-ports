PORTNAME=	poly2tri
DISTVERSION=	g20191130
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D constrained Delaunay triangulation library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		compiler:c11 gl localbase:ldflags waf
USE_GITHUB=	yes
GH_ACCOUNT=	jhasse
GH_TAGNAME=	e6e63dd29ef0805b3e40fe1832c2f1fe2307943a
USE_GL=		gl

PLIST_FILES=	bin/p2t

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/p2t

.include <bsd.port.mk>
