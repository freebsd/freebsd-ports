# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fdupes
PORTVERSION=	2.0.0
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fdupes is a program for identifying or deleting duplicate files

LICENSE=	MIT

LIB_DEPENDS=	libpcre2-32.so:devel/pcre2

USES=		autoreconf libtool localbase pkgconfig
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	adrianlopezroche

OPTIONS_DEFINE=	NCURSES
OPTIONS_DEFAULT=NCURSES

NCURSES_USES=	ncurses:base
NCURSES_CONFIGURE_OFF=	--without-ncurses

PLIST_FILES=	bin/fdupes man/man1/fdupes.1.gz
NCURSES_PLIST_FILES=	man/man7/fdupes-help.7.gz

.include <bsd.port.mk>
