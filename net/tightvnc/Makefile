# Created by: ijliao
# $FreeBSD$

PORTNAME=	tightvnc
PORTVERSION=	1.3.10
PORTREVISION=	6
CATEGORIES=	net java
MASTER_SITES=	SF/vnc-tight/TightVNC-unix/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Enhanced version of VNC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

BROKEN_aarch64=	Fails to build: invokes x86 asm
USES=		cpe imake jpeg shebangfix perl5 tar:bzip2 xorg
USE_XORG=	ice sm x11 xaw xext xmu xt xpm

RUN_DEPENDS=	showrgb:x11/rgb \
		xauth:x11/xauth \
		xorg-fonts>=7.2:x11-fonts/xorg-fonts

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	tigervnc-*
WRKSRC=		${WRKDIR}/vnc_unixsrc
SHEBANG_FILES=	vncserver
CFLAGS+=	-Wno-return-type
ALL_TARGET=	World

OPTIONS_DEFINE=	JVNC_VIEWER
OPTIONS_SUB=	yes
JVNC_VIEWER_DESC=	Install Java-based vnc viewer
JVNC_VIEWER_USE=	JAVA=yes
JVNC_VIEWER_VARS=	JAVA_RUN=yes

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

do-install-JVNC_VIEWER-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/classes/*.* ${STAGEDIR}${DATADIR}/classes

.include <bsd.port.post.mk>
