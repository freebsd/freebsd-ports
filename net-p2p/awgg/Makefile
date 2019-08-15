# $FreeBSD$

PORTNAME=	awgg
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Advanced wget GUI

LICENSE=	GPLv2

RUN_DEPENDS=	aria2c:www/aria2 \
		wget:ftp/wget \
		curl:ftp/curl \
		youtube-dl:www/youtube_dl \
		axel:ftp/axel

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

USES=		fpc lazarus:flavors
USE_FPC=	chm fcl-base fcl-db fcl-image fcl-json fcl-registry fcl-xml \
		pasjpeg regexpr rtl-extra rtl-objpas x11
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Nenirey
GH_PROJECT=	AWGG
GH_TAGNAME=	28d009f

DESKTOP_ENTRIES="AWGG" \
		"Advanced wget GUI" \
		"${PREFIX}/share/pixmaps/AWGG16x16.png" \
		"${PORTNAME}" \
		"Network;P2P;" \
		${TRUE}

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

LAZBUILD_ARGS=	-d
LAZARUS_PROJECT_FILES=	src/awgg.lpi

post-patch:
	${REINPLACE_CMD} 's|/usr/bin/shutdown|/sbin/shutdown|g' ${WRKSRC}/src/fmain.pas
	${REINPLACE_CMD} 's|/usr|${LOCALBASE}|g' ${WRKSRC}/src/fmain.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/pixmaps && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
