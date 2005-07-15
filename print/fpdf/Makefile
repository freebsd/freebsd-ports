# New ports collection makefile for: fpdf
# Date created:		21 March 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	fpdf
PORTVERSION=	1.53
PORTREVISION=	2
CATEGORIES=	print www
MASTER_SITES=	http://www.fpdf.org/fr/
DISTNAME=	${PORTNAME}${PORTVERSION:S|.||}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A free PHP class to generate PDF files with pure PHP

USE_PHP=	zlib

FETCH_CMD=	/usr/bin/fetch -ARr -o ${DISTDIR}/${DISTFILES}
NO_BUILD=	yes

FPDF_DIR?=	share/fpdf

SUB_FILES=	pkg-message
SUB_LIST=	FPDF_DIR=${FPDF_DIR}
PLIST_SUB=	FPDF_DIR=${FPDF_DIR}

EXT2CNV=	afm htm php txt
DOCS=		FAQ.htm doc/* fpdf.css histo.htm install.txt tutoriel

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}dl.php?v=${PORTVERSION:S|.||}&f=${EXTRACT_SUFX:S|.||}'; \
	fi

pre-patch:
.for ext in ${EXT2CNV}
	@for f in `${FIND} ${WRKSRC} -type f -name "*.${ext}"` ; do	\
		${TR} -d '\r' < $$f > $$f.dos &&			\
		${MV} $$f.dos $$f ; done
.endfor
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

do-install:
	${MKDIR} ${PREFIX}/${FPDF_DIR}
	${INSTALL_DATA} ${WRKSRC}/fpdf.php ${PREFIX}/${FPDF_DIR}
	${CP} -R ${WRKSRC}/font ${PREFIX}/${FPDF_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
