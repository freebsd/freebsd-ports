# New ports collection makefile for:	pidgin-birthday_reminder
# Date created:				11 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	pidgin-birthday-reminder
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://launchpadlibrarian.net/56075754/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The birthday reminder for Pidgin

LIB_DEPENDS=	purple.10:${PORTSDIR}/net-im/libpurple
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin


GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		gettext
USE_GNOME=	pkgconfig intltool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
