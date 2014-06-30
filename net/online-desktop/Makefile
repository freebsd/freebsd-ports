# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	online-desktop
PORTVERSION=	0.3.2
PORTREVISION=	8
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GNOME Online Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/nspr.pc:${PORTSDIR}/devel/nspr \
		${LOCALBASE}/libdata/pkgconfig/nss.pc:${PORTSDIR}/security/nss \
		${LOCALBASE}/libdata/pkgconfig/purple.pc:${PORTSDIR}/net-im/libpurple \
		${LOCALBASE}/libdata/pkgconfig/pidgin.pc:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnspr4.so:${PORTSDIR}/devel/nspr \
		libnss3.so:${PORTSDIR}/security/nss \
		libpurple.so:${PORTSDIR}/net-im/libpurple
RUN_DEPENDS=	${LOCALBASE}/libexec/desktop-data-engine:${PORTSDIR}/net/desktop-data-model \
		${LOCALBASE}/bin/bigboard:${PORTSDIR}/misc/bigboard \
		${LOCALBASE}/bin/purple-remote:${PORTSDIR}/net-im/libpurple \
		${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin

DEPRECATED=	Disappeared upstream, depends on expired ports
EXPIRATION_DATE=2014-07-21

USES=		gettext gmake libtool tar:bzip2
USE_GNOME=	glib20 gconf2 pygnomedesktop
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
GCONF_SCHEMAS=	online-desktop.schemas
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f -exec fgrep -l '%%PREFIX%%' {} \; |${XARGS} ${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' -i .bak

.include <bsd.port.mk>
