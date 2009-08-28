# New ports collection makefile for:	odt2txt
# Date created:				2007/01/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	odt2txt
PORTVERSION=	0.4
CATEGORIES=	textproc
MASTER_SITES=	http://stosberg.net/odt2txt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple (and stupid) converter from OpenDocument Text to plain text

USE_GMAKE=	yes
USE_ICONV=	yes
CPPFLAGS+=	-DICONV_CHAR="const char" -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/odt2txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
