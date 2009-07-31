# New ports collection makefile for:	pidgin-rhythmbox
# Date created:		2007-06-28
# Whom:			Yuri Pankov <yuri@darklight.org.ru>
#
# $FreeBSD$
#

PORTNAME=	pidgin-rhythmbox
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	net-im audio
MASTER_SITES=	http://jon.oberheide.org/projects/pidgin-rhythmbox/downloads/

MAINTAINER=	yuri@darklight.org.ru
COMMENT=	Plugin to update your status with info from Rhythmbox

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
		rhythmbox:${PORTSDIR}/audio/rhythmbox

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-rhythmbox.la \
		lib/pidgin/pidgin-rhythmbox.so

post-patch:
		@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
			-e 's#\([@(]\)PIDGIN_INSTALL\([@)]\)#\1libdir\2/pidgin#' \
			-e 's#-g -g3 -O2##'

.include <bsd.port.mk>
