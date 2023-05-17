PORTNAME=	kinfocenter
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 utility providing system information
WWW=		https://www.kde.org/plasma-desktop

RUN_DEPENDS=	lscpu:sysutils/lscpu \
		glxinfo:graphics/mesa-demos \
		vulkaninfo:graphics/vulkan-tools \
		xdpyinfo:x11/xdpyinfo \
		clinfo:devel/clinfo

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig qt:5 \
		tar:xz xorg
USE_GL=		egl gl glu
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdeclarative kio notifications package parts service solid \
		sonnet textwidgets unitconversion wayland widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build \
		systemsettings:run
USE_QT=		concurrent core dbus declarative gui network printsupport \
		widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

# TODO	-- this should be handled correctly...
LDFLAGS+=-ldevinfo

# install freebsd-logo and distrorc
post-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}/images
	${INSTALL_DATA} ${FILESDIR}/freebsd_logo.svg   ${STAGEDIR}/${DATADIR}/images/
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/xdg
	${INSTALL_DATA} ${FILESDIR}/kcm-about-distrorc ${STAGEDIR}/${PREFIX}/etc/xdg/
	${REINPLACE_CMD} -i "" -e "s#%%DATADIR%%#${DATADIR}#"  ${STAGEDIR}/${PREFIX}/etc/xdg/kcm-about-distrorc

.include <bsd.port.mk>
