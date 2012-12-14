# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	mtpfs
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adebenham.com/mtpfs/

MAINTAINER=	john@pcbsd.org
COMMENT=	MTP device filesystem

LIB_DEPENDS=	mtp:${PORTSDIR}/audio/libmtp \
		id3-3.8:${PORTSDIR}/audio/id3lib \
		id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad

USE_FUSE=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mtpfs

.include <bsd.port.mk>
