# New ports collection makefile for:	gaim-xmms-remote
# Date created:		2004-08-31
# Whom:			daniel@xbox-irc.net
#
# $FreeBSD$
#

PORTNAME=	gaim-xmms-remote
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	guifications

MAINTAINER=	danielshafer@gmail.com
COMMENT=	Plugin to display current XMMS song in Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#\([@(]\)GAIM_LIBDIR\([@)]\)#\1libdir\2#' \
		-e 's#\([@(]\)GAIM_DATADIR\([@)]\)#\1datadir\2#'

.include <bsd.port.mk>
