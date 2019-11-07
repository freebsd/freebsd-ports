# $FreeBSD$

PORTNAME=	MolScript
DISTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display 3D molecules in schematic and detailed representations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	render:graphics/raster3d # molscript use requires the executable 'render' to be present

USES=		gl gmake jpeg localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	pekrau
GH_TAGNAME=	280abee
USE_GL=		gl glu glut
USE_XORG=	x11 xext xmu

MAKEFILE=	Makefile.complete

MAKE_ARGS=	CC=${CC} COPT="${CFLAGS}"
CFLAGS+=	-I${FILESDIR}
WRKSRC_SUBDIR=	code

BINARY_ALIAS=	make=${MAKE_CMD}

PROGS=		${PORTNAME:tl} molauto

PLIST_FILES=	${PROGS:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
.for e in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/../${e} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	cd ${WRKSRC}/../docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
