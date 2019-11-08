# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	mtpfs
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adebenham.com/files/mtp/

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	MTP device filesystem

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmtp.so:multimedia/libmtp \
		libid3.so:audio/id3lib \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad

USES=		fuse gnome pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mtpfs

.include <bsd.port.mk>
