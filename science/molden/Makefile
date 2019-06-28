# $FreeBSD$

PORTNAME=	molden
DISTVERSION=	6.1
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.cmbi.umcn.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for molecular and electronic structure visualization

LICENSE=	Molden
LICENSE_NAME=	Molden License
LICENSE_FILE=	${WRKSRC}/CopyRight
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BUILD_DEPENDS=	makedepend:devel/makedepend

USES=		fortran gl gmake localbase
USE_GL=		gl glu
USE_XORG=	x11 xmu

MAKEFILE=	makefile
MAKE_ARGS=	CFLAGS="${CFLAGS}" FFLAGS="${FFLAGS}"

CFLAGS+=	-DFREEBSD -DHASTIMER
FFLAGS+=	-DFREEBSD

EXES=		molden gmolden ambfor/ambfor ambfor/ambmd surf/surf
PLIST_FILES=	${EXES:C/.*\///:S/^/bin\//}

OPTIONS_DEFINE=		DOCS

PORTDOCS=	*

RESTRICTED=	No commercial use

do-install:
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in figures.ps.Z manual.ps.Z  manual.txt.Z
	${INSTALL_DATA} ${WRKSRC}/doc/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
