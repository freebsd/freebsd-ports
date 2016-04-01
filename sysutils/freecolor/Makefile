# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	freecolor
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/freecolor/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Displays free memory as a bargraph

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

GNU_CONFIGURE=	yes
MAKE_ENV+=	INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USES=		pkgconfig

PLIST_FILES=	bin/freecolor man/man1/freecolor.1.gz
USES=		pkgconfig

.include <bsd.port.mk>
