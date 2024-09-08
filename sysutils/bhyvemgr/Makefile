PORTNAME=	bhyvemgr
DISTVERSIONPREFIX=	v
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	bhyve manager GUI written in Lazarus/Freepascal
WWW=		https://github.com/alonsobsd/bhyvemgr

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	bhyve-firmware>0:sysutils/bhyve-firmware \
		virt-viewer>0:net-mgmt/virt-viewer \
		freerdp3>0:net/freerdp3 \
		sudo>0:security/sudo

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils fpc lazarus:flavors xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	alonsobsd

LAZARUS_PROJECT_FILES=	bhyvemgr.lpi

LAZBUILD_ARGS=		-d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
