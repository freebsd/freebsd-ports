# New ports collection makefile for:	telepathy-mission-control
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-mission-control/Makefile,v 1.11 2010/04/23 17:01:23 marcus Exp $

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.3.2
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GNOME=	gnomeprefix pkgconfig gconf2 libxslt gnomehack ltverhack
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MAN1=		mc-account-convert.1 mc-tool.1 mc-wait-for-name.1
MAN8=		mission-control-5.8

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/gtk-doc/html|/${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
