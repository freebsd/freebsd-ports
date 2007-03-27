# Ports collection makefile for:	ekg2
# Date created:				27 Dec 2005
# Whom:					Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	20060519
CATEGORIES=	polish net-im
MASTER_SITES=	http://www.ekg2.org/archive/

MAINTAINER=	alex@bsdguru.org
COMMENT=	Text-mode Gadu-Gadu, Jabber and IRC client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_GETTEXT=	yes
USE_GCC=	3.2+

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--with-expat \
			--without-aspell \
			--without-gtk \
			--without-libgsm \
			--without-libxosd \
			--without-perl \
			--without-python \
			--without-sqlite3 \
			--without-sqlite \
			--without-gpm-mouse \
			--with-libgadu

CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lintl"
MAKE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
