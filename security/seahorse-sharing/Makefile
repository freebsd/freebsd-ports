# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/seahorse-sharing/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	seahorse-sharing
PORTVERSION=	3.6.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Seahorse PGP public key sharing using DNS-SD and HKP.

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libavahi-glib.so:${PORTSDIR}/net/avahi-app \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		seahorse>=3.2.1:${PORTSDIR}/security/seahorse

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	intlhack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
