# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/accountsservice/Makefile 19237 2014-03-23 07:57:22Z gusi $

PORTNAME=	accountsservice
PORTVERSION=	0.6.37
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USE_GNOME=	glib20 gnomehier intlhack introspection:build libxslt
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-systemd --localstatedir=/var/
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gdm/custom.conf|${LOCALBASE}/etc/gdm/custom.conf|g' \
		${WRKSRC}/src/daemon.c
	@${REINPLACE_CMD} -e 's|/lib/AccountsService|/db/AccountsService|g' \
		${WRKSRC}/src/user.c ${WRKSRC}/src/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>

