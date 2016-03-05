# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pdfcrack
PORTVERSION=	0.15
CATEGORIES=	security print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cracking tool for password-protected PDF-files

LICENSE=	GPLv2+

PLIST_FILES=	bin/pdfcrack bin/pdfreader
ALL_TARGET=	pdfcrack pdfreader

post-patch:
	${REINPLACE_CMD} 's,-O.* -g,,' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:Mbin/*:S,bin/,${WRKSRC}/,g} \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
