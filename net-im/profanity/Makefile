PORTNAME=	profanity
DISTVERSION=	0.15.1
CATEGORIES=	net-im
MASTER_SITES=	https://profanity-im.github.io/tarballs/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Console based XMPP client
WWW=		http://www.profanity.im/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libotr.so:security/libotr \
		libuuid.so:misc/libuuid \
		libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt \
		libsignal-protocol-c.so:net/libsignal-protocol-c \
		libstrophe.so:net-im/libstrophe \
		libqrencode.so:graphics/libqrencode

USES=		cpe gmake gnome libtool ncurses pkgconfig python \
		readline sqlite:3
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-otr --enable-python-plugins --enable-c-plugins \
		--enable-plugins --enable-pgp --disable-icons-and-clipboard \
		--without-xscreensaver --disable-gdk-pixbuf \
		--enable-omemo --enable-omemo-qrcode --enable-year2038

OPTIONS_DEFINE=	NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notifications

post-patch:
	${REINPLACE_CMD} "s,python3-embed,python-${PYTHON_VER}-embed,g" \
		${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/man/man1 "-name *\.1"

.include <bsd.port.mk>
