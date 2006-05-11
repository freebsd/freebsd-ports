# New ports collection makefile for:	gaim-extprefs
# Date created:				28 November 2005
# Whom:					Victor Semionov <semionov@mail.bg>
#
# $FreeBSD$
#

PORTNAME=	gaim-extprefs
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gaim-extprefs

MAINTAINER=	semionov@mail.bg
COMMENT=	A gaim plugin that provides additional preferences

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--enable-static=no
CFLAGS+=	"-fPIC"

PLIST_FILES=	lib/gaim/libextprefs.la lib/gaim/libextprefs.so

post-patch:
	@${REINPLACE_CMD} -e 's/-g3//' ${WRKSRC}/configure

.include <bsd.port.mk>
