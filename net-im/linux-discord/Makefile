PORTNAME=	discord
DISTVERSION=	0.0.110
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	https://dl.discordapp.net/apps/linux/${DISTVERSION}/
PKGNAMEPREFIX=	linux-

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Official client for the Discord platform (Linux version)
WWW=		https://discord.com/

LICENSE=	AGPLv3 BSD3CLAUSE CC-BY-2.5 CC-BY-3.0 DISCORD LGPL21 MIT MPL11
LICENSE_COMB=	multi
LICENSE_NAME_DISCORD=	Discord's Term of Service
LICENSE_TEXT_DISCORD=	https://discord.com/terms
LICENSE_PERMS_DISCORD=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	pulseaudio:audio/pulseaudio

USES=		linux:rl9
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk ca-certificates cups-libs dbuslibs devtools gtk3 \
		imageformats-libs libdrm libva nspr nss opus

DATADIR=	${PREFIX}/share/${PKGBASE}

NO_BUILD=	yes
SUB_FILES=	${PKGBASE} pkg-message
SUB_LIST=	LINUXBASE=${LINUXBASE}

NO_WRKSUBDIR=	yes

ICONS_DIR=	${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps

post-patch:
	${REINPLACE_CMD} -i "" \
		-e 's,/usr,${PREFIX},g' \
		-e 's,\(^Exec=\).*,\1${PREFIX}/bin/${PKGBASE},1' \
		${WRKSRC}/Discord/discord.desktop

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
