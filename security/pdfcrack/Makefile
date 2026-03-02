PORTNAME=	pdfcrack
PORTVERSION=	0.21
CATEGORIES=	security print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Cracking tool for password-protected PDF-files
WWW=		https://sourceforge.net/projects/pdfcrack/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	pdfcrack pdfreader
PLIST_FILES=	bin/pdfcrack bin/pdfreader share/man/man1/pdfcrack.1.gz

post-patch:
	${REINPLACE_CMD} 's,-O.* -g,,' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:Mbin/*:S,bin/,${WRKSRC}/,g} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pdfcrack.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
