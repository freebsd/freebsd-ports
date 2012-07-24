# New ports collection makefile for:	xcode
# Date created:		13 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	xcode
PORTVERSION=	4.1
CATEGORIES=	russian converters
MASTER_SITES=	http://www.rusf.ru/books/yo/src/ \
		http://pankovpv.sovietservers.com/stuff/freebsd-distfiles/
DISTNAME=	xcodesrc

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A program for converting Russian encodings with care to letter YO

PLIST_FILES=	bin/xcode
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	xcode
CFLAGS+=	-DD_KOI

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xcode ${PREFIX}/bin

.include <bsd.port.mk>
