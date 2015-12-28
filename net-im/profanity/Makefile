# $FreeBSD$

PORTNAME=	profanity
PORTVERSION=	0.4.7
CATEGORIES=	net-im
MASTER_SITES=	http://www.profanity.im/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Console based XMPP client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libstrophe.so:${PORTSDIR}/net-im/libstrophe \
		libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libotr.so:${PORTSDIR}/security/libotr3 \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libgpgme.so:${PORTSDIR}/security/gpgme

OPTIONS_DEFINE=NOTIFY
USES=		ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-otr
CONFIGURE_ENV=	LIBS="${CFLAGS} -lcrypto"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-notifications
.endif

.include <bsd.port.mk>
