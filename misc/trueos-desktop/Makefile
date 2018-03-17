# $FreeBSD$

PORTNAME=	trueos-desktop
PORTVERSION=	201803131015
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS Desktop

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	trueos-core>=0:misc/trueos-core \
		${LOCALBASE}/sbin/PCDMd:x11/pcdm \
		${LOCALBASE}/bin/qsudo:sysutils/qsudo \
		${LOCALBASE}/bin/pc-wificonfig:sysutils/pc-networkmanager \
		${LOCALBASE}/bin/pc-firstgui:sysutils/trueos-utils \
		${LOCALBASE}/bin/pc-firstboot:sysutils/trueos-utils-qt5 \
		${LOCALBASE}/bin/pc-mixer:audio/pc-mixer \
		${LOCALBASE}/bin/sysadm-client:sysutils/sysadm-client \
		${LOCALBASE}/bin/personacrypt:sysutils/personacrypt \
		${LOCALBASE}/bin/pc-webkitviewer:www/pc-webkitviewer \
		${LOCALBASE}/bin/xdg-open:devel/xdg-utils \
		${LOCALBASE}/bin/xvkbd:x11/xvkbd \
		cups-filters>=0:print/cups-filters \
		trueos-handbook>=0:misc/trueos-handbook \
		lumina>=0:x11/lumina \
		foomatic-db>=0:print/foomatic-db \
		fluxbox-tenr-styles-pack>=0:x11-themes/fluxbox-tenr-styles-pack \
		xorg-minimal>=0:x11/xorg-minimal \
		xorg-drivers>=0:x11-drivers/xorg-drivers \
		nss_mdns>=0:dns/nss_mdns \
		cuse4bsd-kmod>=0:multimedia/cuse4bsd-kmod \
		webcamd>=0:multimedia/webcamd \
		x11vnc>=0:net/x11vnc \
		git:devel/git \
		xv>=0:graphics/xv \
		socat>=0:net/socat \
		mesa-demos>=0:graphics/mesa-demos \
		/boot/modules/drm.ko:graphics/drm-next-kmod \
		xdg-user-dirs>=0:devel/xdg-user-dirs

CONFLICTS=      pcbsd-utils-[0-9]* trueos-server-[0-9]*

WRKSRC_SUBDIR=	package-files
MAKE_ARGS=	STAGEDIR=${STAGEDIR}  TYPE=desktop

USE_GITHUB=     yes
GH_ACCOUNT=     trueos
GH_PROJECT=     trueos-core
GH_TAGNAME=     f8b9f07940a9b460351f2dfe2c7d53fbe0e832f1

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/pixmaps
	${LN} -s ${PREFIX}/share/pixmaps ${STAGEDIR}${PREFIX}/share/icons/hicolor/pixmaps/apps

.include <bsd.port.mk>
