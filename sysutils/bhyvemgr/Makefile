PORTNAME=	bhyvemgr
DISTVERSIONPREFIX=	v
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	bhyve manager GUI written in Lazarus/Freepascal
WWW=		https://github.com/alonsobsd/bhyvemgr

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	virt-viewer>0:net-mgmt/virt-viewer \
		sudo>0:security/sudo

ONLY_FOR_ARCHS?=amd64

USES=		desktop-file-utils fpc lazarus:flavors xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	alonsobsd

OPTIONS_DEFINE=		FREERDP3

FREERDP3_DESC=		Install freerdp3 to enable rdp connection option
FREERDP3_RUN_DEPENDS=	freerdp3>0:net/freerdp3

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500000)
ONLY_FOR_ARCHS=	aarch64 amd64
.endif

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1403000)
RUN_DEPENDS+=	swtpm>0:sysutils/swtpm
.endif

.if ${ARCH} == "aarch64"
RUN_DEPENDS+=	u-boot-bhyve-arm64>0:sysutils/u-boot-bhyve-arm64
.elif ${ARCH} == "amd64"
RUN_DEPENDS+=	bhyve-firmware>0:sysutils/bhyve-firmware
.endif

LAZARUS_PROJECT_FILES=	src/bhyvemgr.lpi

LAZBUILD_ARGS=		--bm=Release -d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/setup/${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images" ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
