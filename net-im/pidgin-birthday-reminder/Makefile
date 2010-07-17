# New ports collection makefile for:	pidgin-birthday_reminder
# Date created:				11 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	pidgin-birthday-reminder
PORTVERSION=	1.6
CATEGORIES=	net-im
MASTER_SITES=	http://launchpadlibrarian.net/48067464/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	The birthday reminder for Pidgin

LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	pkgconfig intltool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
