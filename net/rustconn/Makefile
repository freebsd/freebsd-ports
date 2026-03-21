PORTNAME=	rustconn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.15
CATEGORIES=	net

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Modern connection manager with GTK4/Wayland-native interface
WWW=		https://github.com/totoshko88/RustConn

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 CDLA20 \
		GPLv3 ISCL MIT MPL20 OpenSSL UNICODE UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libgraphene-1.0.so:graphics/graphene \
		libzstd.so:archivers/zstd

USES=		cargo gettext-tools gnome shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	totoshko88
GH_PROJECT=	RustConn
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 libadwaita pango vte3

SHEBANG_FILES=	po/compile-mo.sh

CARGO_INSTALL_PATH=	${PORTNAME} ${PORTNAME}-cli

RUSTCONN_DOCS=	BITWARDEN_SETUP.md USER_GUIDE.md

OPTIONS_DEFINE=	DOCS KUBERNETES NLS RDP SERIAL VNC
OPTIONS_SUB=	yes

KUBERNETES_DESC=	Use sysutils/kubectl to access Kubernetes
RDP_DESC=		Use net/freerdp3 for RDP connections
SERIAL_DESC=		Use comms/picocom for serial connections
VNC_DESC=		Use net/tigervnc-viewer for VNC connections
KUBERNETES_RUN_DEPENDS=	kubectl:sysutils/kubectl
NLS_USES=		gettext-runtime
RDP_RUN_DEPENDS=	freerdp3>=3.23.0:net/freerdp3
SERIAL_RUN_DEPENDS=	picocom:comms/picocom
VNC_RUN_DEPENDS=	vncviewer:net/tigervnc-viewer

NLS_DIR=	${STAGEDIR}${PREFIX}/share/locale

do-build-NLS-on:
	(cd ${WRKSRC} && ./po/compile-mo.sh ${CARGO_TARGET_DIR}/locale)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && \
		${INSTALL_DATA} ${RUSTCONN_DOCS} ${STAGEDIR}${DOCSDIR})

do-install-NLS-on:
	${MKDIR} ${NLSDIR}
	(cd ${CARGO_TARGET_DIR}/locale && ${COPYTREE_SHARE} . ${NLS_DIR})

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/assets/io.github.totoshko88.RustConn.desktop \
		${STAGEDIR}${DESKTOPDIR}/
.for size in 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/assets/icons/hicolor/${size}x${size}/apps/io.github.totoshko88.RustConn.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/assets/icons/hicolor/scalable/apps/io.github.totoshko88.RustConn.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
