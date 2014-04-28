# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/gnome-keyring/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	gnome-keyring
PORTVERSION=	3.12.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
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

USE_GNOME=	gnomeprefix gtk30 intlhack libxslt:build
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
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
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-keyring/devel/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pkcs11/gnome-keyring-pkcs11.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_gnome_keyring.so

.include <bsd.port.mk>
