# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	pdftohtml
PORTVERSION=	0.39
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line tool for converting pdf-files into html

CONFLICTS=	poppler-utils-[0-9]*

USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/pdftohtml

WRKSRC=		${WRKDIR}/${DISTNAME}

NO_STAGE=	yes
pre-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-O[0-9]||" -e "s|-g||"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pdftohtml ${PREFIX}/bin

.include <bsd.port.mk>
