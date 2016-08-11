# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	fpdf
PORTVERSION=	1.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	print www
MASTER_SITES=	http://www.fpdf.org/en/
DISTNAME=	${PORTNAME}${PORTVERSION:S|.||}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Free PHP class to generate PDF files with pure PHP

BROKEN_powerpc64=	Does not build

USE_PHP=	zlib

FETCH_CMD=	${FETCH_BINARY} -ARr -o ${DISTDIR}/${DISTFILES}
USES=		dos2unix tar:tgz
NO_BUILD=	yes

FPDF_DIR?=	share/fpdf

SUB_FILES=	pkg-message
SUB_LIST=	FPDF_DIR=${FPDF_DIR}
PLIST_SUB=	FPDF_DIR=${FPDF_DIR}

EXT2CNV=	afm css htm php txt
DOCS=		FAQ.htm changelog.htm doc fpdf.css install.txt license.txt tutorial

OPTIONS_DEFINE=	DOCS

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}dl.php?v=${PORTVERSION:S|.||}&f=${EXTRACT_SUFX:S|.||}'; \
	fi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FPDF_DIR}
	${INSTALL_DATA} ${WRKSRC}/fpdf.php ${STAGEDIR}${PREFIX}/${FPDF_DIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "font makefont" ${STAGEDIR}${PREFIX}/${FPDF_DIR}/)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
