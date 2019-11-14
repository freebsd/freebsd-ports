# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	secpanel
PORTVERSION=	0.6.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	security tcl tk
MASTER_SITES=	SF/${PORTNAME} \
		SF/nemysisfreebsdp/security/:icons
DISTFILES=	${DISTNAME}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

LICENSE=	GPLv2

RUN_DEPENDS=	ssh-askpass:security/openssh-askpass

USES=		tk:wrapper

OPTIONS_RADIO=	TERMINAL
OPTIONS_RADIO_TERMINAL=	GNOMETERMINAL MATETERMINAL XTERM
OPTIONS_DEFAULT=	GNOMETERMINAL

GNOMETERMINAL_DESC=	build with gnome-terminal
MATETERMINAL_DESC=	build with mate-terminal (you need mate-desktop)
XTERM_DESC=		build with xterm
GNOMETERMINAL_RUN_DEPENDS=	gnome-terminal>=3.0.0:x11/gnome-terminal
MATETERMINAL_RUN_DEPENDS=	mate-terminal:x11/mate-terminal
XTERM_RUN_DEPENDS=		xterm:x11/xterm

WRKSRC=		${WRKDIR}/${PREFIX}
NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATETERMINAL}
USES+=		mate
USE_MATE=	desktop
.endif

DESKTOP_ENTRIES="SecPanel" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" ""  ${FALSE}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\[file dirname \[info script\]\]/../lib/secpanel|${DATADIR}|' \
			${WRKSRC}/bin/secpanel

do-install:
.if ${PORT_OPTIONS:MMATETERMINAL}
	${REINPLACE_CMD} 's|set configs(termver) "Xterm"|set configs(termver) "MATE-Terminal"|' \
		${WRKSRC}/bin/secpanel
	${REINPLACE_CMD} 's|Xterm|MATE-Terminal|' \
		${WRKSRC}/lib/secpanel/default.config
.elif ${PORT_OPTIONS:MGNOMETERMINAL}
	${REINPLACE_CMD} 's|set configs(termver) "Xterm"|set configs(termver) "GNOME-Terminal"|' \
		${WRKSRC}/bin/secpanel
	${REINPLACE_CMD} 's|Xterm|GNOME-Terminal|' \
		${WRKSRC}/lib/secpanel/default.config
.endif

	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/lib/secpanel && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${CHMOD} u+rw ${STAGEDIR}${DATADIR}/default.config
	${MV} ${STAGEDIR}${DATADIR}/default.config ${STAGEDIR}${DATADIR}/default.config.sample

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
