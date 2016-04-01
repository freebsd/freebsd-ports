# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-ews
PORTVERSION=	3.18.5
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through Exchange Web Services

BUILD_DEPENDS=	evolution>=3.0.0:mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libmspack.so:archivers/libmspack \
		libical.so:devel/libical
RUN_DEPENDS=	evolution>=3.0.0:mail/evolution

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig sqlite tar:xz
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_BDB=	5
USE_OPENLDAP=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datarootdir=${PREFIX}/share \
		--localedir=${PREFIX}/share/locale \
		--prefix=${PREFIX}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
