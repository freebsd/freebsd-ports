PORTNAME=	uml2svg
PORTVERSION=	0.18
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL stylesheets to convert UML to SVG

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
NO_ARCH=	yes

INSTDIR=	share/xsl/uml2svg

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/xsl
	dirs=$$(${FIND} ${WRKSRC}/src/xsl -type d | ${SED} 's|^${WRKSRC}/src/xsl||g'); \
	for d in $${dirs}; do \
		files=$$(${FIND} ${WRKSRC}/src/xsl/$${d} -type f); \
		${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/xsl/$${d}; \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${INSTDIR}/xsl/$${d}; \
			done; \
		done; \
		files=$$(${FIND} ${WRKSRC}/src/xsl -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${INSTDIR}/xsl/; \
	done
	${INSTALL_DATA} ${WRKSRC}/src/uml2svg.xsl ${STAGEDIR}${PREFIX}/${INSTDIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
