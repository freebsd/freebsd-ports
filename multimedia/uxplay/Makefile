PORTNAME=	uxplay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.73.3
CATEGORIES=	multimedia

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AirPlay Unix mirroring server
WWW=		https://github.com/FDH2/UxPlay

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdns_sd.so:net/avahi-libdns \
		libplist-2.0.so:devel/libplist

USES=		cmake gettext-runtime gnome gstreamer localbase:ldflags \
		pkgconfig python shebangfix ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FDH2
GH_PROJECT=	UxPlay
USE_GNOME=	glib20
USE_GSTREAMER=	core plugins
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	Bluetooth_LE_beacon/dbus/uxplay-beacon.py \
		Bluetooth_LE_beacon/winrt/uxplay-beacon.py

CMAKE_ARGS=	-DNO_MARCH_NATIVE=on

SUB_FILES=	pkg-message

PLIST_FILES=	bin/uxplay \
		bin/uxplay-beacon.py \
		share/man/man1/uxplay-beacon.1.gz \
		share/man/man1/uxplay.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
