# New ports collection makefile for:	ssvnc
# Date created:				2007-04-22
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ssvnc
PORTVERSION=	1.0.20
PORTREVISION=	6
CATEGORIES=	net security
MASTER_SITES=	http://www.karlrunge.com/x11vnc/etv/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhanced TightVNC Viewer (SSVNC: SSL/SSH VNC viewer)

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	stunnel:${PORTSDIR}/security/stunnel

USE_XORG=	xi xmu xt xaw
USE_TCL_RUN=	84
USE_TK_RUN=	84
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g; s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/build.unix
	@${REINPLACE_CMD} -e \
		's|exec wish|exec ${WISH}|; \
		 303,$$s|ss_vncviewer|ssvnc-stunnel|; \
		 s|ssvnc_cmd|ssvnc-stunnel|' \
		 ${WRKSRC}/bin/util/ssvnc.tcl
	@${REINPLACE_CMD} -e \
		's|ss_vncviewer|ssvnc-stunnel|; \
		 s|-vncviewer|-ssvnc|; \
		 s|grep Linux|grep ${OPSYS}|' \
		 ${WRKSRC}/bin/util/ss_vncviewer

do-build:
	@cd ${WRKSRC} && ${SETENV} UNAME="${OPSYS}" ${SH} build.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${OPSYS}/vncviewer ${PREFIX}/bin/ssvnc
	${INSTALL_SCRIPT} ${WRKSRC}/bin/util/ss_vncviewer \
		${PREFIX}/bin/ssvnc-stunnel
	${INSTALL_SCRIPT} ${WRKSRC}/bin/util/ssvnc.tcl ${PREFIX}/bin/ssvnc-gui
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README bin/util/stunnel-server.conf \
		${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
