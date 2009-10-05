# New ports collection makefile for:	fusefs-gphotofs
# Date created: 			05 October 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gphotofs
PORTVERSION=	0.4.0
CATEGORIES=	sysutils graphics
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	avl@FreeBSD.org
COMMENT=	FUSE-based filesystem for digital cameras

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
