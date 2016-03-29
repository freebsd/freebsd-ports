# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	pdftohtml
PORTVERSION=	0.40a
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Experimental%20Versions/${PORTNAME}%20${PORTVERSION:S|a||} \
		http://fossies.org/linux/www/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool for converting pdf-files into html

USES=		ghostscript gmake

PLIST_FILES=	bin/pdf-to-html

pre-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-O[0-9]||" -e "s|-g||"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pdftohtml \
		${STAGEDIR}${PREFIX}/bin/pdf-to-html

.include <bsd.port.mk>
