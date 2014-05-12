# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/glib-networking/Makefile 18537 2013-06-16 20:08:30Z kwm $

PORTNAME=	glib-networking
PORTVERSION=	2.36.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Network-related giomodules for glib

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intltool
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GNUTLS PKCS11 PROXY GNOME_PROXY
OPTIONS_DEFAULT=GNUTLS PKCS11 PROXY GNOME_PROXY
OPTIONS_SUB=	yes

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls
PKCS11_DESC=		Enable PKCS11 support (requires GNUTLS)
PKCS11_LIB_DEPENDS=	libp11-kit.so:${PORTSDIR}/security/p11-kit \
			libgnutls.so:${PORTSDIR}/security/gnutls
PKCS11_CONFIGURE_WITH=	pkcs11
PROXY_LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy
PROXY_CONFIGURE_WITH=	libproxy
GNOME_PROXY_DESC=	Support for GNOME proxy configuration
GNOME_PROXY_BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
GNOME_PROXY_RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
GNOME_PROXY_CONFIGURE_WITH=	gnome-proxy

post-patch:
	@${REINPLACE_CMD} -e' s|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.mk>
