# New ports collection makefile for:	telepathy-idle
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	telepathy-idle
PORTVERSION=	0.1.4
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

LIB_PC_DEPENDS=	gobject-2.0.pc:${PORTSDIR}/devel/glib20 \
		dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib.pc:${PORTSDIR}/net-im/telepathy-glib

BUILD_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g} \
    		xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20

MAN8=		telepathy-idle.8

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.post.mk>
