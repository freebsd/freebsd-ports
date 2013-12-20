# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/accountsservice/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	accountsservice
PORTVERSION=	0.6.24
PORTREVISION=	3
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USE_GNOME=	glib20 gnomehier intlhack introspection:build libxslt
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-systemd --localstatedir=/var/ --disable-vala
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

