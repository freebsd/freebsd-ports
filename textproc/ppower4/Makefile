# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	ppower4
PORTVERSION=	0.9.4
PORTREVISION=	7
CATEGORIES=	textproc java
MASTER_SITES=	TEX_CTAN/support/${PORTNAME}
DISTFILES=	pp4sty.zip pp4p.jar manual.pdf leveldemo.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	pp4sty.zip leveldemo.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Post processor for PDF presentations made with (La)TeX

USES=		zip
USE_TEX=	latex
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

JAR_DIR=	${JAVASHAREDIR}/${PORTNAME}
STY_DIR=	${PREFIX}/share/texmf/tex/latex/${PORTNAME}
STY_FILES=	${WRKDIR}/pause.sty ${WRKDIR}/background.sty \
		${WRKDIR}/pp4link.sty ${WRKDIR}/mpmulti.sty
EXAMPLE_FILES=	${WRKDIR}/leveldemo.tex
.for i in 1 2 3 4 5 6 7
EXAMPLE_FILES+=	${WRKDIR}/example.${i}
.endfor
PLIST_SUB=	STY_DIR="${STY_DIR:S,^${PREFIX}/,,}" \
		JAR_DIR="${JAR_DIR:S,^${PREFIX}/,,}"

SUB_FILES=	ppower4.sh
SUB_LIST=	JARFILE=${JAR_DIR}/pp4p.jar

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf \
		${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLE_FILES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${STY_DIR}
	${INSTALL_DATA} ${STY_FILES} ${STAGEDIR}${STY_DIR}
	@${MKDIR} ${STAGEDIR}${JAR_DIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pp4p.jar ${STAGEDIR}${JAR_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/ppower4.sh ${STAGEDIR}${PREFIX}/bin/ppower4

.include <bsd.port.mk>
