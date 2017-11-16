# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pdfcrack
PORTVERSION=	0.16
CATEGORIES=	security print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cracking tool for password-protected PDF-files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/pdfcrack bin/pdfreader man/man1/pdfcrack.1.gz
ALL_TARGET=	pdfcrack pdfreader

post-patch:
	${REINPLACE_CMD} 's,-O.* -g,,' ${WRKSRC}/Makefile

post-build:
	${COMPRESS_CMD} < ${WRKSRC}/pdfcrack.1 > ${WRKSRC}/pdfcrack.1.gz

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:Mbin/*:S,bin/,${WRKSRC}/,g} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${PLIST_FILES:Mman/*:S,man/man1/,${WRKSRC}/,g}	\
		${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
