# New ports collection makefile for:	gaim-openq
# Date created:		2004-10-12
# Whom:		 	hamigua@hotpop.com
#
# $FreeBSD$
#

PORTNAME=	openq
PORTVERSION=	0.3.2
PORTREVISION=	9
CATEGORIES=	net-im
MASTER_SITES=	SF
PKGNAMEPREFIX=	gaim-

PATCH_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
PATCHFILES=	openq-0.3.2.qq2006.group.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A QQ-liked protocol plugin for Gaim

BUILD_DEPENDS=	${LOCALBASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_AUTOTOOLS=	libtool:15
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
