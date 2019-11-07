# Created by: Jay Sachs <sachs@cs.williams.edu>
# $FreeBSD$

PORTNAME=	plugger
PORTVERSION=	5.1.5
CATEGORIES=	www audio graphics multimedia
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia front-end plugin for Mozilla or Opera

USES=		webplugin:native xorg
USE_XORG=	xext xt sm ice xext x11
GNU_CONFIGURE=	yes

PKGDEINSTALL=	${PKGINSTALL}

WEBPLUGIN_FILES=npplugger.so

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/X11R6/lib/xscreensaver|${LOCALBASE}/bin/xscreensaver-hacks|g' \
		-e 's|+useFrontEndProgram||g' \
		${WRKSRC}/pluggerrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PORTVERSION} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/plugger-oohelper \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/plugger.so \
		${STAGEDIR}${WEBPLUGIN_DIR}/npplugger.so
	${INSTALL_DATA} ${WRKSRC}/pluggerrc \
		${STAGEDIR}${PREFIX}/etc/pluggerrc-${PORTVERSION}.sample
	${INSTALL_MAN} ${WRKSRC}/plugger.7 ${STAGEDIR}${MANPREFIX}/man/man7

local-install:
	@${MKDIR} ${HOME}/.plugger
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PORTVERSION} \
		${HOME}/.plugger
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller \
		${HOME}/.plugger
	${INSTALL_SCRIPT} ${WRKSRC}/plugger-oohelper \
		${HOME}/.plugger
	if [ -f ${HOME}/.plugger/pluggerrc-${PORTVERSION} ]; then \
		${MV} ${HOME}/.plugger/pluggerrc-${PORTVERSION} \
			${HOME}/.plugger/pluggerrc-${PORTVERSION}.old; \
	fi
	${INSTALL_DATA} ${WRKSRC}/pluggerrc \
		${HOME}/.plugger/pluggerrc-${PORTVERSION}

local-mozilla-install: local-install
	@${MKDIR} ${HOME}/.mozilla/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${HOME}/.mozilla/plugins/npplugger.so

local-opera-install: local-install
	@${MKDIR} ${HOME}/.opera/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${HOME}/.opera/plugins/npplugger.so

.include <bsd.port.mk>
