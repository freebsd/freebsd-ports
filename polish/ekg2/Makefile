# Ports collection makefile for:	ekg2
# Date created:				27 Dec 2005
# Whom:					Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$

PORTNAME=	ekg2
PORTVERSION=	0.1.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	polish net-im
MASTER_SITES=	http://pl.ekg2.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu, Jabber and IRC client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_GETTEXT=	yes

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
			CFLAGS="${CFLAGS}" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}"
MAKE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CFLAGS+=		-I${LOCALBASE}/include

USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
