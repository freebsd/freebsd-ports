PORTNAME=	touchegg
DISTVERSION=	2.0.18
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-touch gesture recognizer
WWW=		https://github.com/JoseExposito/touchegg

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libgudev>0:devel/libgudev
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libinotify.so:devel/libinotify \
		libinput.so:x11/libinput \
		libpugixml.so:textproc/pugixml \
		libudev.so:devel/libudev-devd

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gnome localbase:ldflags pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11 xi xrandr xtst

USE_GITHUB=	yes
GH_ACCOUNT=	JoseExposito

CMAKE_OFF=	USE_SYSTEMD USE_SYSTEMD
CMAKE_ARGS=	-DCMAKE_INSTALL_FULL_DATAROOTDIR=${LOCALBASE}/etc \
		-DCMAKE_INSTALL_DATAROOTDIR=etc

LDFLAGS+=	-linotify

post-install:
	@${MV} \
		${STAGEDIR}${ETCDIR}/touchegg.conf \
		${STAGEDIR}${ETCDIR}/touchegg.conf.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/touchegg

.include <bsd.port.mk>
