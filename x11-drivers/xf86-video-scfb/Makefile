# Created by: Florent Thoumie <flz@freebsd.org>
# $FreeBSD$

PORTNAME=	xf86-video-scfb
PORTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	x11-drivers

# Runtime fix from https://github.com/rayddteam/xf86-video-scfb/pull/4
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	080491f.patch:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org syscons display driver

USES=		xorg-cat:driver
PLIST_FILES=	lib/xorg/modules/drivers/scfb_drv.so \
		man/man4/scfb.4x.gz

USE_GITHUB=	yes
GH_ACCOUNT=	rayddteam

.include <bsd.port.mk>
