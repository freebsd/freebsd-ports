# New ports collection makefile for:	ppower4
# Date created:		07 November 2003
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	ppower4
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}
DISTFILES=	pp4sty.zip pp4p.jar manual.pdf leveldemo.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	pp4sty.zip leveldemo.zip

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Post processor for PDF presentations made with (La)TeX

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_ZIP=	yes
USE_JAVA=	1.3+
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
NO_WRKSUBDIR=	yes

JAR_DIR=	${JAVAJARDIR}/${PORTNAME}
STY_DIR=	${PREFIX}/share/texmf/tex/latex/${PORTNAME}
STY_FILES=	${WRKDIR}/pause.sty ${WRKDIR}/background.sty \
		${WRKDIR}/pp4link.sty ${WRKDIR}/mpmulti.sty
EXAMPLE_FILES=	${WRKDIR}/leveldemo.tex
.for i in 1 2 3 4 5 6 7
EXAMPLE_FILES+=	${WRKDIR}/example.${i}
.endfor
PLIST_SUB=	STY_DIR="${STY_DIR:S,^${PREFIX}/,,}" \
		JAR_DIR="${JAR_DIR:S,^${PREFIX}/,,}"

post-patch:
# prepare wrapper script
	@${SED} -e "s,%%JAVAVM%%,${LOCALBASE}/bin/javavm,; \
		s,%%JARFILE%%,${JAR_DIR}/pp4p.jar," \
		${FILESDIR}/ppower4 > ${WRKDIR}/ppower4

do-install:
# install docs?
.if !defined(NOPORTDOCS)
# install docs...
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${DOCSDIR}
# ...and the examples, too!
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLE_FILES} ${EXAMPLESDIR}
.endif
# install data files
	@${MKDIR} ${STY_DIR}
	@${INSTALL_DATA} ${STY_FILES} ${STY_DIR}
	@${MKDIR} ${JAR_DIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/pp4p.jar ${JAR_DIR}
# install wrapper script
	@${INSTALL_SCRIPT} ${WRKDIR}/ppower4 ${PREFIX}/bin/ppower4

post-install:
	${SETENV} LOCALBASE=${LOCALBASE} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
