# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	gnomint
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	X.509 Certification Authority management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

BUILD_DEPENDS=	intltool-update:${PORTSDIR}/textproc/intltool

GNU_CONFIGURE=	yes
USES=		gmake perl5 pkgconfig readline
USE_GNOME=	gconf2 gdkpixbuf2 glib20 gtk20

CFLAGS:=	${CFLAGS:C/-Werror//}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
