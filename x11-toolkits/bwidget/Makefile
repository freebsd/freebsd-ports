# Created by: Alexander Kabaev <ak03@gte.com>
# $FreeBSD$

PORTNAME=	bwidget
PORTVERSION=	1.9.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcllib/BWidget/${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	High-level widget set for Tcl/Tk

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

OPTIONS_DEFINE=	DOCS

USES=		tk:run zip
NO_BUILD=	yes
PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget/images
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget/lang
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bwidget
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${STAGEDIR}${PREFIX}/lib/bwidget
	cd ${WRKSRC}/images && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/bwidget/images
	cd ${WRKSRC}/lang && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/bwidget/lang
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/BWman
	${INSTALL_DATA} ${WRKSRC}/BWman/*.html ${STAGEDIR}${DOCSDIR}/BWman
. for FILE in CHANGES.txt ChangeLog README.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
. endfor
.endif

.include <bsd.port.mk>
