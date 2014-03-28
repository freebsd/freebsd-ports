# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	pdftohtml
PORTVERSION=	0.39
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool for converting pdf-files into html

USES=		gmake
USE_GHOSTSCRIPT_RUN=	yes

PLIST_FILES=	bin/pdf-to-html

WRKSRC=		${WRKDIR}/${DISTNAME}

pre-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-O[0-9]||" -e "s|-g||"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pdftohtml \
		${STAGEDIR}${PREFIX}/bin/pdf-to-html

.include <bsd.port.mk>
