# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	mtpfs
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adebenham.com/files/mtp/

MAINTAINER=	john@pcbsd.org
COMMENT=	MTP device filesystem

LIB_DEPENDS=	libmtp.so:${PORTSDIR}/multimedia/libmtp \
		libid3.so:${PORTSDIR}/audio/id3lib \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libmad.so:${PORTSDIR}/audio/libmad

USES=		fuse pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mtpfs

.include <bsd.port.mk>
