# New ports collection makefile for:	odt2txt
# Date created:				2007/01/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	odt2txt
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://stosberg.net/odt2txt/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	A simple converter from OpenDocument Text to plain text

LICENSE=	GPLv2

USE_GMAKE=	yes
USES=		iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/odt2txt

MAN1=		odt2txt.1

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		-e 's#-liconv#${ICONV_LIB}#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/odt2txt ${PREFIX}/bin/odt2txt
	${INSTALL_MAN} ${WRKSRC}/odt2txt.1 ${MANPREFIX}/man/man1/odt2txt.1

.include <bsd.port.mk>
