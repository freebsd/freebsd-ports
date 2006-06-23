# New ports collection makefile for:	gxine
# Date created:	Sa 19 Apr 2003 01:34:06 CEST
# Whom: 	Grigori Goronzy <greg@chown.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	gxine
PORTVERSION=	0.3.3
PORTREVISION=	16
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xine

MAINTAINER=	greg@chown.ath.cx
COMMENT=	An alternative GUI for the Xine media player

LIB_DEPENDS=	xine.15:${PORTSDIR}/multimedia/libxine

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gtk20 gnomehier
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -I${X11BASE}/lib"

MANLANG=	"" de
MAN1=		gxine.1

OPTIONS=	MOZILLA_PLUGIN "Install Mozilla plugin" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MOZILLA_PLUGIN)
PLIST_SUB+=	MOZILLA_PLUGIN="@comment "
.else
PLIST_SUB+=	MOZILLA_PLUGIN=""
.endif

post-install:
.if !defined(WITHOUT_MOZILLA_PLUGIN)
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	@${LN} -sf ${PREFIX}/lib/gxine/gxineplugin.so ${PREFIX}/lib/browser_plugins
.endif

.include <bsd.port.post.mk>
