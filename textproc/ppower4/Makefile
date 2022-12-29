PORTNAME=	ppower4
PORTVERSION=	0.9.4
PORTREVISION=	8
CATEGORIES=	textproc java
MASTER_SITES=	TEX_CTAN/support/${PORTNAME}
DISTFILES=	pp4sty.zip pp4p.jar manual.pdf leveldemo.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	pp4sty.zip leveldemo.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Post processor for PDF presentations made with (La)TeX
WWW=		https://ctan.org/tex-archive/support/ppower4/

LICENSE=	GPLv2 # version not really specified

USES=		tex zip
USE_JAVA=	yes
USE_TEX=	latex

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	ppower4.sh
SUB_LIST=	JARFILE=${JAR_DIR}/pp4p.jar

NO_WRKSUBDIR=	yes

JAR_DIR=	${JAVASHAREDIR}/${PORTNAME}
STY_DIR=	${PREFIX}/share/texmf/tex/latex/${PORTNAME}
STY_FILES=	${WRKSRC}/pause.sty ${WRKSRC}/background.sty \
		${WRKSRC}/pp4link.sty ${WRKSRC}/mpmulti.sty
EXAMPLE_FILES=	${WRKSRC}/leveldemo.tex
.for i in 1 2 3 4 5 6 7
EXAMPLE_FILES+=	${WRKSRC}/example.${i}
.endfor
PLIST_SUB=	STY_DIR="${STY_DIR:S,^${PREFIX}/,,}" \
		JAR_DIR="${JAR_DIR:S,^${PREFIX}/,,}"

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${STY_DIR}
	${INSTALL_DATA} ${STY_FILES} ${STAGEDIR}${STY_DIR}
	@${MKDIR} ${STAGEDIR}${JAR_DIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pp4p.jar ${STAGEDIR}${JAR_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/ppower4.sh ${STAGEDIR}${PREFIX}/bin/ppower4

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLE_FILES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
