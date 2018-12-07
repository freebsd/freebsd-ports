# Created by: Alexander Kabaev <ak03@gte.com>
# $FreeBSD$

PORTNAME=	bwidget
PORTVERSION=	1.9.13
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcllib/BWidget/${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	High-level widget set for Tcl/Tk

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tk:run zip

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget/images
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget/lang
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${STAGEDIR}${PREFIX}/lib/bwidget
	cd ${WRKSRC}/images && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/bwidget/images
	cd ${WRKSRC}/lang && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/bwidget/lang

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/BWman
	${INSTALL_DATA} ${WRKSRC}/BWman/*.html ${STAGEDIR}${DOCSDIR}/BWman
.for FILE in CHANGES.txt ChangeLog README.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
.endfor

.include <bsd.port.mk>
