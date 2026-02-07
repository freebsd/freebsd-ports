PORTNAME=	pdf4tcl
PORTVERSION=	0.94
CATEGORIES=	print devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Pure Tcl library to generate PDF files
WWW=		https://sourceforge.net/projects/pdf4tcl/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/licence.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	dtplite:devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//}

PLIST_FILES=	lib/${PORTNAME}/glyph2uni.tcl \
		lib/${PORTNAME}/pkgIndex.tcl \
		lib/${PORTNAME}/pdf4tcl.tcl \
		lib/${PORTNAME}/stdmetrics.tcl \
		share/man/mann/pdf4tcl.n.gz

do-build:
	${LOCALBASE}/bin/dtplite -o ${WRKSRC}/pdf4tcl.n nroff ${WRKSRC}/pdf4tcl.man

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	${INSTALL_MAN} ${WRKSRC}/pdf4tcl.n ${STAGEDIR}${PREFIX}/share/man/mann/

.include <bsd.port.mk>
