# Created by: ijliao
# $FreeBSD$

PORTNAME=	tightvnc
PORTVERSION=	1.3.10
PORTREVISION=	4
CATEGORIES=	net java
MASTER_SITES=	SF/vnc-tight/TightVNC-unix/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Enhanced version of VNC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

RUN_DEPENDS=	showrgb:x11/rgb \
		xauth:x11/xauth \
		xorg-fonts>=7.2:x11-fonts/xorg-fonts

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	tridiavnc-[0-9]* vnc-[0-9]*
WRKSRC=		${WRKDIR}/vnc_unixsrc
USES=		cpe imake jpeg shebangfix perl5 tar:bzip2
SHEBANG_FILES=	vncserver
CFLAGS+=	-Wno-return-type
USE_XORG=	xaw
ALL_TARGET=	World

OPTIONS_DEFINE=	JVNC_VIEWER
JVNC_VIEWER_DESC=	Install Java-based vnc viewer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJVNC_VIEWER}
USE_JAVA=	yes
JAVA_RUN=	yes
PLIST_SUB+=	JVNC_VIEWER=""
.else
PLIST_SUB+=	JVNC_VIEWER="@comment "
.endif

.ifdef(TIGHTVNC_BASE)
PREFIX=${TIGHTVNC_BASE}
.endif

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/share/vnc/classes/index.vnc)
IGNORE=		vnc has already been installed, please uninstall it first
.endif

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def
	@${REINPLACE_CMD} -i '' -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -i '' -e "s|/usr/local/vnc/classes|${DATADIR}/classes|g" \
		${WRKSRC}/vncserver
	@${REINPLACE_CMD} -i '' -e "s|%%CC%%|${CC}|g ; \
		s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Xvnc/config/cf/FreeBSD.cf

do-install:
	@(cd ${WRKSRC}; ./vncinstall ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/man)
.if defined(STRIP) && ${STRIP} != ""
.for FILE in Xvnc vncviewer vncpasswd vncconnect
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${FILE}
.endfor
.endif
.if ${PORT_OPTIONS:MJVNC_VIEWER}
	@${MKDIR} ${STAGEDIR}${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/classes/*.* ${STAGEDIR}${DATADIR}/classes
.endif

.include <bsd.port.post.mk>
