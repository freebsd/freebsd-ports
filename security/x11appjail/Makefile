PORTNAME=	x11appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Tool for creating, verifying, installing, and running AppJails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	appjail:sysutils/appjail \
		appscript:archivers/appscript \
		doas:security/doas \
		git:devel/git@lite \
		jtransfer:sysutils/jtransfer \
		notify-send:devel/libnotify \
		unixexec:sysutils/unixexec \
		update-desktop-database:devel/desktop-file-utils \
		xauth:x11/xauth \
		xclipsync:sysutils/xclipsync \
		xdg-open:devel/xdg-utils \
		xdotool:x11/xdotool \
		Xephyr:x11-servers/xorg-server@xephyr \
		xev:x11/xev \
		xseticon:x11/xseticon \
		zenity:x11/zenity4

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	x11appjail

NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		BLAKE3
OPTIONS_DEFAULT=	BLAKE3

BLAKE3_DESC=		Enable support for Blake3
BLAKE3_RUN_DEPENDS=	b3sum:sysutils/b3sum

.include <bsd.port.mk>
