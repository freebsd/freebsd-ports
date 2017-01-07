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
		libcurl.so:ftp/curl \
		libotr.so.5:security/libotr \
		libuuid.so:misc/e2fsprogs-libuuid \
		libgpgme.so:security/gpgme

USES=		ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-otr
CONFIGURE_ENV=	LIBS="${CFLAGS} -lcrypto"
USE_GNOME=	glib20

OPTIONS_DEFINE=	NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notifications

.include <bsd.port.mk>
