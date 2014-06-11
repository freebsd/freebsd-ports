# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C ${STAGEDIR}${DOCSDIR})
.endif
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

.include <bsd.port.post.mk>
