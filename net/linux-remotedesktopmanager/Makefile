PORTNAME=	linux-remotedesktopmanager
DISTVERSION=	2026.3.0.5
CATEGORIES=	net linux
MASTER_SITES=	https://cdn.devolutions.net/download/Linux/RDM/${DISTVERSION}/
DISTNAME=	RemoteDesktopManager_${DISTVERSION}_amd64
EXTRACT_SUFX=	.deb
EXTRACT_ONLY=	${DISTNAME}.tar.xz

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Centralize, manage and secure remote connections
WWW=		https://devolutions.net/remote-desktop-manager/

LICENSE=	EULA
LICENSE_NAME=	Devolutions Software License and Subscription Agreement
LICENSE_TEXT=	Redistribution of the binaries is not permitted, \
		see https://devolutions.net/legal/customer-agreements/
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only amd64 binaries are provided by the vendor

EXTRACT_DEPENDS=	deb2targz:archivers/deb2targz
RUN_DEPENDS=	dbus-run-session:devel/dbus

USES=		desktop-file-utils linux:rl9 shared-mime-info tar:xz
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk ca-certificates cups-libs dbuslibs dri enchant2 \
		fontconfig freetype gdkpixbuf2 gstreamer1 gtk3 harfbuzz \
		harfbuzz-icu hyphen icu imageformats-libs lcms2 libdrm \
		libepoxy libgcrypt libglvnd librsvg2 libseccomp libsecret \
		libusb libxml2 libxslt nss pango pulseaudio-libs systemd-libs \
		vte291 webkit2gtk3 xorglibs

NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

NO_WRKSUBDIR=	yes

pre-extract:
	${LOCALBASE}/bin/deb2targz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-extract:
	@${RM} ${DISTDIR}/${DISTNAME}.tar.xz

post-patch:
	@${REINPLACE_CMD} -i "" -e 's,^Exec=remotedesktopmanager,Exec=${PREFIX}/bin/${PORTNAME},' \
		${WRKSRC}/usr/share/applications/com.devolutions.remotedesktopmanager.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/usr/lib/devolutions/RemoteDesktopManager && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR} && ${CHMOD} ${BINMODE} createdump \
		jetsocat RemoteDesktopManager RemoteDesktopManager.NativeMessagingHost)
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	(cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \
		"applications icons metainfo mime" ${STAGEDIR}${PREFIX}/share)

.include <bsd.port.mk>
