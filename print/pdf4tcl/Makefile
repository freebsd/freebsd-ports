PORTNAME=	pdf4tcl
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Pure Tcl library to generate PDF files
WWW=		https://sourceforge.net/projects/pdf4tcl/

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	dtplite:devel/tcllib
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib/snit/snit.tcl:devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//}

PORTDOCS=	*
PLIST_FILES=	lib/${PKGNAME}/glyph2uni.tcl \
		lib/${PKGNAME}/pkgIndex.tcl \
		lib/${PKGNAME}/pdf4tcl.tcl \
		lib/${PKGNAME}/stdmetrics.tcl \
		share/man/mann/pdf4tcl.n.gz

.include <bsd.port.options.mk>

do-build:
#	Generate manpage
	cd ${WRKSRC} && ${LOCALBASE}/bin/dtplite -o pdf4tcl.n nroff pdf4tcl.man

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PKGNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \*.tcl ${STAGEDIR}${PREFIX}/lib/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/pdf4tcl.n ${STAGEDIR}${PREFIX}/share/man/mann
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
