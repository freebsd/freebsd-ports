# $FreeBSD$

PORTNAME=	profanity
PORTVERSION=	0.8.1
CATEGORIES=	net-im

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Console based XMPP client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libmesode.so:net-im/libmesode \
		libcurl.so:ftp/curl \
		libotr.so.5:security/libotr \
		libuuid.so:misc/e2fsprogs-libuuid \
		libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt \
		libsignal-protocol-c.so:net/libsignal

USES=		ncurses pkgconfig ssl python readline autoreconf libtool gnome
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	profanity-im
GH_PROJECT=	profanity

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-otr --enable-python-plugins --enable-c-plugins \
		--enable-pgp --enable-icons-and-clipboard=no \
		--with-xscreensaver=no \
		--enable-omemo
CONFIGURE_ENV=	LIBS="${CFLAGS} -lcrypto"
INSTALL_TARGET=	install-strip
OPTIONS_DEFINE=	NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notifications

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "s,python-config,${PYTHON_VERSION}-config,g" \
		${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
