# Created by: gahr
# $FreeBSD$

PORTNAME=	pdf4tcl
PORTVERSION=	0.8
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//}${EXTRACT_SUFX}/from_sourceforge

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Pure Tcl library to generate PDF files

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/licence.terms

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib/snit/snit.tcl:${PORTSDIR}/devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//}

PORTDOCS=	*
PLIST_FILES=	lib/${PKGNAME}/glyph2uni.tcl \
		lib/${PKGNAME}/pkgIndex.tcl \
		lib/${PKGNAME}/pdf4tcl.tcl \
		lib/${PKGNAME}/stdmetrics.tcl \
		man/mann/pdf4tcl.n.gz
PLIST_DIRS=	lib/${PKGNAME}

.include <bsd.port.options.mk>

do-build:
#	Generate manpage
	cd ${WRKSRC} && ${LOCALBASE}/bin/dtplite -o pdf4tcl.n nroff pdf4tcl.man

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PKGNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \*.tcl ${STAGEDIR}${PREFIX}/lib/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/pdf4tcl.n ${STAGEDIR}${PREFIX}/man/mann
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
