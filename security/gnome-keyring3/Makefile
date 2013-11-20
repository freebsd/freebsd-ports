# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/gnome-keyring3/Makefile 18410 2013-05-01 15:20:45Z kwm $

PORTNAME=	gnome-keyring
PORTVERSION=	3.6.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gcr>=3.5.3:${PORTSDIR}/security/gcr
LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 ltverhack intlhack
USES=		gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib" \
		--with-root-certs=${LOCALBASE}/share/certs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|make --version|${GMAKE} --version|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gnome-keyring-module|gnome-keyring.module|g' \
		${WRKSRC}/pkcs11/rpc-layer/Makefile.in \
		${WRKSRC}/configure

.include <bsd.port.mk>
