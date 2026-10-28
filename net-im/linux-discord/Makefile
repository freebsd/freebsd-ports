PORTNAME=	discord
DISTVERSION=	1.0.160
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	https://dl.discordapp.net/apps/linux/${DISTVERSION}/ \
		https://stable.dl2.discordapp.net/distro/app/stable/linux/x64/${DISTVERSION}/:distro
PKGNAMEPREFIX=	linux-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		full.distro:distro \
		${DISCORD_MODULES:@m@${m}/${MODULE_VERSION}/full.distro:distro@}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	undefine@undefine.pl
COMMENT=	Official client for the Discord platform (Linux version)
WWW=		https://discord.com/

LICENSE=	AGPLv3 BSD3CLAUSE CC-BY-2.5 CC-BY-3.0 DISCORD LGPL21 MIT MPL11
LICENSE_COMB=	multi
LICENSE_NAME_DISCORD=	Discord's Term of Service
LICENSE_TEXT_DISCORD=	https://discord.com/terms
LICENSE_PERMS_DISCORD=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

EXTRACT_DEPENDS=	brotli:archivers/brotli
PATCH_DEPENDS=	jq:textproc/jq
RUN_DEPENDS=	pulseaudio:audio/pulseaudio

USES=		desktop-file-utils linux:rl9
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk ca-certificates cups-libs dbuslibs devtools gtk3 \
		imageformats-libs libdrm libva nspr nss opus

DATADIR=	${PREFIX}/share/${PKGBASE}

NO_BUILD=	yes
SUB_FILES=	${PKGBASE} pkg-message
SUB_LIST=	LINUXBASE=${LINUXBASE}

NO_WRKSUBDIR=	yes

DISCORD_MODULES=	discord_desktop_core discord_erlpack discord_game_utils \
			discord_krisp discord_rpc discord_spellcheck \
			discord_utils discord_voice discord_zstd
MODULE_VERSION=		1

ICONS_DIR=	${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps

post-extract:
	@cd ${WRKSRC}/Discord && \
	${LOCALBASE}/bin/brotli -cd ${DISTDIR}/${DIST_SUBDIR}/full.distro | \
		/usr/bin/tar -xf - --strip-components 1 && \
	for m in ${DISCORD_MODULES}; do \
		${MKDIR} modules/$${m} && \
		${LOCALBASE}/bin/brotli -cd ${DISTDIR}/${DIST_SUBDIR}/$${m}/${MODULE_VERSION}/full.distro | \
			/usr/bin/tar -xf - -C modules/$${m} --strip-components 1 || exit 1; \
	done

post-patch:
	${REINPLACE_CMD} -i "" \
		-e 's,/usr,${PREFIX},g' \
		-e 's,\(^Exec=\).*,\1${PREFIX}/bin/${PKGBASE},1' \
		${WRKSRC}/Discord/discord.desktop
	${LOCALBASE}/bin/jq '.newUpdater = false | .localModulesRoot = "${DATADIR}/modules"' \
		${WRKSRC}/Discord/resources/build_info.json > ${WRKDIR}/build_info.json
	${MV} ${WRKDIR}/build_info.json ${WRKSRC}/Discord/resources/build_info.json
	${MKDIR} ${WRKSRC}/Discord/modules/discord_krisp/KMS/logs

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/Discord && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		"-not ( -regex \./discord.* -o -name *.orig )")
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGBASE} ${STAGEDIR}${LOCALBASE}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Discord/discord.desktop ${STAGEDIR}${DESKTOPDIR}/${PKGBASE}.desktop
	@${MKDIR} ${ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/Discord/discord.png ${ICONS_DIR}

.include <bsd.port.mk>

