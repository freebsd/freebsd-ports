# Created by: Dmitriy Limonov
# $FreeBSD$

PORTNAME=	ncdc
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://dev.yorhel.nl/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	earl1k@mail.ru
COMMENT=	Lightweight direct connect client with ncurses interface

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3 \
		pcre:${PORTSDIR}/devel/pcre \
		gmp:${PORTSDIR}/math/gmp \
		gnutls:${PORTSDIR}/security/gnutls \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit

USE_PKGCONFIG=	build
USE_NCURSES=	yes
USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		ncdc.1
PLIST_FILES=	bin/ncdc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
