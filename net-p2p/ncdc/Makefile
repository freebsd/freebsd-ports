PORTNAME=	ncdc
DISTVERSION=	1.24.1
CATEGORIES=	net-p2p
MASTER_SITES=	http://dev.yorhel.nl/download/

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface
WWW=		https://dev.yorhel.nl/ncdc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		compiler:c11 gnome localbase:ldflags ncurses pkgconfig sqlite
USE_GNOME=	glib20

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ncdc \
		share/man/man1/ncdc.1.gz

OPTIONS_DEFINE=		GEOIP
OPTIONS_DEFAULT=	GEOIP

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_WITH=	geoip

.include <bsd.port.options.mk>

.if ${OPSYS}_${OSREL:R} == FreeBSD_13
CONFIGURE_ENV= NCURSES_CFLAGS="-L${NCURSESLIB}" NCURSES_LIBS="-lncursesw"
.endif

.include <bsd.port.mk>
