# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bwm-ng
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.gropp.org/bwm-ng/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Small and simple bandwidth monitor

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

GNU_CONFIGURE=	yes
USES=		ncurses pkgconfig
USE_CSTD=	gnu89
PLIST_FILES=	bin/bwm-ng man/man1/bwm-ng.1.gz

CONFIGURE_ARGS=	--with-libstatgrab
CPPFLAGS+=	`pkg-config --cflags libstatgrab`
LIBS+=		`pkg-config --libs libstatgrab`

.include <bsd.port.mk>
