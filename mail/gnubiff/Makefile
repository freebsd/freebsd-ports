PORTNAME=	gnubiff
PORTVERSION=	2.2.13
PORTREVISION=	16
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Mail notification program for Gnome
WWW=		https://gnubiff.sourceforge.net/

LIB_DEPENDS=	libpopt.so:devel/popt

OPTIONS_DEFINE=	NLS

USES=		compiler:c++11-lang cpe fam gmake gnome pkgconfig
USE_GNOME=	intlhack libglade2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

# CXXFLAGS needed to work round issue with gcc and openssl 0.9.8a
# /usr/local/include/openssl/sha.h:173: error: ISO C++ does not support `long long'
CXXFLAGS+=	"-Wno-long-long"

INFO=		gnubiff
CPE_VENDOR=	gnu

.include <bsd.port.options.mk>

.ifdef(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

CONFIGURE_ARGS+=	--disable-gnome

.include <bsd.port.mk>
