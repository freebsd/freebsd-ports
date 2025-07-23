PORTNAME=	awgg
DISTVERSION=	0.6.0.6034-beta
PORTREVISION=	14
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Advanced wget GUI
WWW=		https://github.com/Nenirey/AWGG

LICENSE=	GPLv2

RUN_DEPENDS=	aria2c:www/aria2 \
		wget:ftp/wget \
		curl:ftp/curl \
		yt-dlp:www/yt-dlp

ONLY_FOR_ARCHS=	amd64 i386

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USES=		fpc gnome lazarus:flavors xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Nenirey
GH_PROJECT=	AWGG
GH_TAGNAME=	6daa550

DESKTOP_ENTRIES="AWGG" \
		"Advanced wget GUI" \
		"${PREFIX}/share/pixmaps/AWGG16x16.png" \
		"${PORTNAME}" \
		"Network;P2P;" \
		${TRUE}

USE_GNOME_gtk2=	cairo
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

LAZBUILD_ARGS=	-d --cpu=${ARCH:S/amd64/x86_64/g}
LAZARUS_PROJECT_FILES=	src/awgg.lpi

post-patch:
	${REINPLACE_CMD} 's|/usr/bin/shutdown|/sbin/shutdown|g' ${WRKSRC}/src/fmain.pas
	${REINPLACE_CMD} 's|/usr|${LOCALBASE}|g' ${WRKSRC}/src/fmain.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/pixmaps && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
