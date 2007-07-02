# New ports collection makefile for:	xfs
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfs
PORTVERSION=	1.0.4
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org font server

XORG_CAT=	app
USE_XORG=	libfs xfont xtrans
USE_RC_SUBR=	xfs
ALL_TARGET=	all config

MAN1=		xfs.1

.if !defined(WITHOUT_XFS_CACHE)
USE_XORG+=	fontcacheproto x11
CFLAGS+=	-DFONTCACHE
.else
post-patch:
	${REINPLACE_CMD} -e 's|^cache|XCOMM &|' ${WRKSRC}/config.cpp
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/config ${PREFIX}/lib/X11/fs/config.default
	@if [ ! -f ${PREFIX}/lib/X11/fs/config ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/config ${PREFIX}/lib/X11/fs/config; \
	fi

.include <bsd.port.mk>
