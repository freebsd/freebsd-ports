PORTNAME=	fpdf
DISTVERSION=	1.86
PORTEPOCH=	1
CATEGORIES=	print www
MASTER_SITES=	http://www.fpdf.org/en/dl.php?v=${DISTVERSION:S|.||}&f=${EXTRACT_SUFX:S|.||}&dummy=/
DISTNAME=	${PORTNAME}${DISTVERSION:S|.||}

MAINTAINER=	xaa+ports@dohd.org
COMMENT=	Free PHP class to generate PDF files with pure PHP
WWW=		http://www.fpdf.org/

LICENSE=	As_Is
LICENSE_NAME=	As_Is
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix php tar:tgz
USE_PHP=	zlib
NO_BUILD=	yes
NO_ARCH=	yes

FPDF_DIR?=	share/fpdf

SUB_FILES=	pkg-message
SUB_LIST=	FPDF_DIR=${FPDF_DIR}
PLIST_SUB=	FPDF_DIR=${FPDF_DIR}

EXT2CNV=	afm css htm php txt
DOCS=		FAQ.htm changelog.htm doc fpdf.css install.txt tutorial

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FPDF_DIR}
	${INSTALL_DATA} ${WRKSRC}/fpdf.php ${STAGEDIR}${PREFIX}/${FPDF_DIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "font makefont" ${STAGEDIR}${PREFIX}/${FPDF_DIR}/)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
