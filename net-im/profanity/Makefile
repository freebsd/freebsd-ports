PORTNAME=	profanity
PORTVERSION=	0.12.1
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Console based XMPP client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libmesode.so:net-im/libmesode \
		libcurl.so:ftp/curl \
		libotr.so:security/libotr \
		libuuid.so:misc/e2fsprogs-libuuid \
		libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt \
		libsignal-protocol-c.so:net/libsignal-protocol-c \
		libstrophe.so:net-im/libstrophe

USES=		cpe ncurses pkgconfig ssl python:3.8+ readline autoreconf libtool gnome \
		sqlite:3
CPE_VENDOR=	${PORTNAME}_project
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	profanity-im

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
	${REINPLACE_CMD} "s,python3-embed,python-${PYTHON_VER}-embed,g" \
		${WRKSRC}/configure.ac

post-install:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/man/man1 "-name *\.1"

.include <bsd.port.post.mk>
