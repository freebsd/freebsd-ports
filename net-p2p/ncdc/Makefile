# Created by: Dmitriy Limonov
# $FreeBSD$

PORTNAME=	ncdc
PORTVERSION=	1.18
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://dev.yorhel.nl/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface

LICENSE=	MIT

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libgmp.so:${PORTSDIR}/math/gmp \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit

USES=		gmake pkgconfig ncurses
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/ncdc \
		man/man1/ncdc.1.gz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
