# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/
PKGNAMESUFFIX=	-doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The QtiPlot Handbook

BUILD_DEPENDS=	docbook2html:textproc/docbook-utils \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:textproc/docbook-xsl \
		${LOCALBASE}/share/sgml/docbook/dsssl/modular/html/docbook.dsl:textproc/dsssl-docbook-modular

USES=		tar:bzip2
DATADIR=	${PREFIX}/share/qtiplot/manual
WRKSRC=		${WRKDIR}/${DISTNAME}/manual

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:g" \
		docbook-en/index.docbook qtiplot.dsl qtiplot_html.xsl Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${RM} -r ${WRKSRC}/html/pics-it
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
