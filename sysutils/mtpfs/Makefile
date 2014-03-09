# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	mtpfs
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adebenham.com/files/mtp/

MAINTAINER=	john@pcbsd.org
COMMENT=	MTP device filesystem

LIB_DEPENDS=	mtp:${PORTSDIR}/multimedia/libmtp \
		id3-3.8:${PORTSDIR}/audio/id3lib \
		id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad

USES=		fuse pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mtpfs

NO_STAGE=	yes
.include <bsd.port.mk>
