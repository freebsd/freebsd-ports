# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	pdftohtml
PORTVERSION=	0.40a
CATEGORIES=	textproc
MASTER_SITES=	http://sourceforge.net/projects/${PORTNAME}/files/Experimental%20Versions/${PORTNAME}%200.40/ \
		http://fossies.org/linux/www/

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
