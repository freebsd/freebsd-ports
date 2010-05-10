# New ports collection makefile for: mtpfs
# Date created: 1 July 2007
# Whom: John Hixson <john@divinix.org>
#
# $FreeBSD$
#

PORTNAME=	mtpfs
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adebenham.com/mtpfs/

MAINTAINER=	john@pcbsd.org
COMMENT=	MTP device filesystem

RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
LIB_DEPENDS=	mtp:${PORTSDIR}/audio/libmtp \
		fuse:${PORTSDIR}/sysutils/fusefs-libs \
		id3-3.8:${PORTSDIR}/audio/id3lib \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad

USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mtpfs

.include <bsd.port.mk>
