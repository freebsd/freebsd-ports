# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/
PKGNAMESUFFIX=	-doc

MAINTAINER=	makc@FreeBSD.org
COMMENT=	The QtiPlot Handbook

BUILD_DEPENDS=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/sgml/docbook/dsssl/modular/html/docbook.dsl:${PORTSDIR}/textproc/dsssl-docbook-modular

USE_BZIP2=	yes
DATADIR=	${PREFIX}/share/qtiplot/manual
WRKSRC=		${WRKDIR}/${DISTNAME}/manual

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:g" \
		docbook-en/index.docbook qtiplot.dsl qtiplot_html.xsl Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${RM} -rf ${WRKSRC}/html/pics-it
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
