# $FreeBSD$

PORTNAME=	profanity
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.profanity.im/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Console based XMPP client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libstrophe.so:net-im/libstrophe \
		libglib-2.0.so:devel/glib20 \
		libcurl.so:ftp/curl \
		libotr.so.5:security/libotr \
		libuuid.so:misc/e2fsprogs-libuuid \
		libgpgme.so:security/gpgme

USES=		ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-otr
CONFIGURE_ENV=	LIBS="${CFLAGS} -lcrypto"

OPTIONS_DEFINE=	NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notifications

.include <bsd.port.mk>
