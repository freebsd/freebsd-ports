# New ports collection makefile for:   uml2svg
# Date created:        22 January 2009
# Whom:                Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uml2svg
PORTVERSION=	0.18
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL stylesheets to convert UML to SVG

NO_BUILD=	yes

INSTDIR=	share/xsl/uml2svg

.include <bsd.port.pre.mk>

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${DOCSDIR})
.endif
	${MKDIR} ${PREFIX}/${INSTDIR}/xsl
	dirs=$$(${FIND} ${WRKSRC}/src/xsl -type d | ${SED} 's|^${WRKSRC}/src/xsl||g'); \
	for d in $${dirs}; do \
		files=$$(${FIND} ${WRKSRC}/src/xsl/$${d} -type f); \
		${MKDIR} ${PREFIX}/${INSTDIR}/xsl/$${d}; \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${PREFIX}/${INSTDIR}/xsl/$${d}; \
			done; \
		done; \
		files=$$(${FIND} ${WRKSRC}/src/xsl -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${PREFIX}/${INSTDIR}/xsl/; \
	done
	${INSTALL_DATA} ${WRKSRC}/src/uml2svg.xsl ${PREFIX}/${INSTDIR}/

plist:
	${FIND} ${PREFIX}/${INSTDIR} -type f | ${SED} 's|${PREFIX}/||g' | ${SORT} >${PLIST}
	${FIND} ${PREFIX}/${INSTDIR} -type d | ${SORT} -r | ${SED} -e 's|${PREFIX}/||g' -e 's|^|@dirrm |g' >>${PLIST}
	${FIND} ${DOCSDIR} -type f | ${SED} 's|${DOCSDIR}/|%%PORTDOCS%%%%DOCSDIR%%/|g' | ${SORT} >>${PLIST}
	${FIND} ${DOCSDIR} -type d | ${SORT} -r | ${SED} 's|${DOCSDIR}/|%%PORTDOCS%%@dirrm %%DOCSDIR%%/|g' >>${PLIST}

.include <bsd.port.post.mk>
