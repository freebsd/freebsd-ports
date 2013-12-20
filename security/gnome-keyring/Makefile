# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/gnome-keyring/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-keyring
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	gnome-keyring-3.[0-9]* gcr-3.[0-9]*

NO_STAGE FUCK YEAH!
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gtk20 ltverhack intlhack
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib" \
		--with-root-certs="${LOCALBASE}/share/certs/ca-root-nss.crt"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml \
		org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
