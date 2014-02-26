# Created by: chinsan
# $FreeBSD$

PORTNAME=	odt2txt
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://stosberg.net/odt2txt/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Simple converter from OpenDocument Text to plain text

LICENSE=	GPLv2

USES=		iconv gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/odt2txt man/man1/odt2txt.1.gz

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		-e 's#-liconv#${ICONV_LIB}#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odt2txt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/odt2txt.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
