PORTNAME=	profanity
DISTVERSION=	0.18.0
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Console based XMPP client
WWW=		http://www.profanity.im/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libstrophe.so:net-im/libstrophe

USES=		cpe gnome meson ncurses pkgconfig readline sqlite:3
CPE_VENDOR=	${PORTNAME}_project
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	profanity-im

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			NOTIFY PYTHON C OTR PGP OMEMO QRCODE CLIPBOARD \
				AVATAR SCREENSAVER SPELLCHECK MIME
OPTIONS_SINGLE=			OMEMO-BACKEND
OPTIONS_SINGLE_OMEMO-BACKEND=	LIBSIGNAL \
				LIBOMEMO
OPTIONS_DEFAULT=		NOTIFY PYTHON C OMEMO LIBOMEMO QRCODE SPELLCHECK \
				CLIPBOARD MIME
OPTIONS_SUB=		C

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_ENABLED=	notifications
NOTIFY_DESC=		Enables desktop notifications

PYTHON_USES=		python
PYTHON_MESON_ENABLED=	python-plugins
PYTHON_DESC=		Enables support for Python plugins

C_MESON_ENABLED=	c-plugins
C_DESC=			Enables support for C plugins

OTR_LIB_DEPENDS=	libotr.so:security/libotr
OTR_MESON_ENABLED=	otr
OTR_DESC=		Enables support for Off The Record (OTR) encryption

PGP_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libassuan.so:security/libassuan \
			libgpg-error.so:security/libgpg-error
PGP_MESON_ENABLED=	pgp
PGP_DESC=		Enables support for PGP encryption

OMEMO_MESON_ENABLED=	omemo
OMEMO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
OMEMO_DESC=		Enables support for OMEMO encryption

LIBSIGNAL_MESON_ON=	-Domemo-backend=libsignal
LIBSIGNAL_LIB_DEPENDS=	libsignal-protocol-c.so:net/libsignal-protocol-c
LIBSIGNAL_DESC=		Use libsignal-protocol-c as the OMEMO backend

LIBOMEMO_MESON_ON=	-Domemo-backend=libomemo-c
LIBOMEMO_LIB_DEPENDS=	libomemo-c.so:security/libomemo-c
LIBOMEMO_DESC=		Use libomemo-c as the OMEMO backend

QRCODE_MESON_ENABLED=	omemo-qrcode
QRCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODE_DESC=		Enables support for generating OMEMO QR codes

CLIPBOARD_MESON_ENABLED=	icons-and-clipboard
CLIPBOARD_USE=		GNOME=gtk30
CLIPBOARD_DESC=			Enables support for tray icons and clipboard

AVATAR_MESON_ENABLED=	gdk-pixbuf
AVATAR_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2
AVATAR_DESC=		Enables support for avatar scaling

SCREENSAVER_MESON_ENABLED=		xscreensaver
SCREENSAVER_DESC=			Enables support for idle detection
SCREENSAVER_USES=	xorg
SCREENSAVER_USE=	XORG=xscrnsaver

SPELLCHECK_MESON_ENABLED=	spellcheck
SPELLCHECK_DESC=		Enables support for spell checking
SPELLCHECK_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2

MIME_RUN_DEPENDS=	update-mime-database:misc/shared-mime-info
MIME_DESC=		Use the correct MIME types for uploads

post-patch:
	${REINPLACE_CMD} -e 's,python3-embed,python-${PYTHON_VER}-embed,' \
		${WRKSRC}/meson.build

post-install:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/man/man1 "-name *\.1"

.include <bsd.port.mk>
