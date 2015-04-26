# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	gnomint
PORTVERSION=	1.2.1
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	X.509 Certification Authority management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake perl5 pkgconfig readline
USE_GNOME=	gconf2 gdkpixbuf2 glib20 gtk20

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
