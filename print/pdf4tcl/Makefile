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

RUN_DEPENDS=	${LOCALBASE}/lib/tcllib/snit/snit.tcl:${PORTSDIR}/devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//}

NO_BUILD=	yes
PORTDOCS=	*
PLIST_FILES=	lib/${PKGNAME}/glyph2uni.tcl \
		lib/${PKGNAME}/pkgIndex.tcl \
		lib/${PKGNAME}/pdf4tcl.tcl \
		lib/${PKGNAME}/stdmetrics.tcl
PLIST_DIRS=	lib/${PKGNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${PREFIX}/lib/${PKGNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \*.tcl ${PREFIX}/lib/${PKGNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
