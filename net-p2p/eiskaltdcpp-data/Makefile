# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp-data
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Shared data for EiskaltDC++ GUIs

LICENSE=	GPLv3

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	EMOTICONS EXAMPLES LUASCRIPTS SOUND
OPTIONS_DEFAULT=	EMOTICONS SOUNDS
EMOTICONS_DESC=		Install emoticons
EXAMPLES_DESC=		Install script examples
LUASCRIPTS_DESC=	Install lua script examples
SOUNDS_DESC=		Install sound files

NO_STAGE=	yes
.include <bsd.port.options.mk>

DATA_DIR=	${PREFIX}/share/eiskaltdcpp

.if ${PORT_OPTIONS:MEMOTICONS}
PLIST_SUB+=	EMOTICONS=""
.else
PLIST_SUB+=	EMOTICONS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MLUASCRIPTS}
PLIST_SUB+=	LUASCRIPTS=""
.else
PLIST_SUB+=	LUASCRIPTS="@comment "
.endif

.if ${PORT_OPTIONS:MSOUNDS}
PLIST_SUB+=	SOUNDS=""
.else
PLIST_SUB+=	SOUNDS="@comment "
.endif

do-install:
	@${MKDIR} ${DATA_DIR}
	@${TOUCH} ${DATA_DIR}/keep_me
.for SIZE in 16x16 22x22 24x24 32x32 48x48 64x64 128x128
	@${MKDIR} "${LOCALBASE}/share/icons/hicolor/${SIZE}/apps"
	@${CP} -v "${WRKSRC}/icons/icon_${SIZE}.png" "${LOCALBASE}/share/icons/hicolor/${SIZE}/apps/eiskaltdcpp.png"
.endfor
.if ${PORT_OPTIONS:MEMOTICONS}
	@${CP} -rv ${WRKSRC}/emoticons ${DATA_DIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${DATA_DIR}/examples
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${DATA_DIR}/examples
.endif
.if ${PORT_OPTIONS:MLUASCRIPTS}
	@${CP} -rv ${WRKSRC}/luascripts ${DATA_DIR}
.endif
.if ${PORT_OPTIONS:MSOUNDS}
	@${CP} -rv ${WRKSRC}/sounds ${DATA_DIR}
.endif

.include <bsd.port.mk>
