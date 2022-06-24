# Created by: Kevin Zheng <kevinz5000@gmail.com>

PORTNAME=	gnomint
PORTVERSION=	1.2.1
PORTREVISION=	13
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X.509 Certification Authority management tool

DEPRECATED=	Abandonware, depending on gconf2
EXPIRATION_DATE=	2022-07-24

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libsqlite3.so:databases/sqlite3

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake gnome perl5 pkgconfig readline
USE_GNOME=	gconf2 gdkpixbuf2 glib20 gtk20 intltool

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
