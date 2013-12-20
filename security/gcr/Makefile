# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/security/gcr/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gcr
PORTVERSION=	3.6.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gtk-doc>0:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gtk30 intlhack introspection:build
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
