# New ports collection makefile for:   wmshutdown
# Date created:        26 November 2002
# Whom:                nishida
#
# $FreeBSD$
#

PORTNAME=	wmShutdown
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://grad.icmc.usp.br/~rva/pkgs/

MAINTAINER=	kaname@vamp.jpn.ph
COMMENT=	Window Maker dock application to shutdown or reboot

USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${ECHO} "wmShutdown -- Rafael V. Aroca <rafael@linuxqos.cjb.net>"
	@${MKDIR} ${PREFIX}/share/wmShutdown/pixmaps && ${CHMOD} a+rx ${PREFIX}/share/wmShutdown/pixmaps
	@${INSTALL_PROGRAM} ${WRKSRC}/wmShutdown ${PREFIX}/bin
	@${INSTALL_PROGRAM} -g wheel -o root ${WRKSRC}/Shutdown ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/Shutdown ${PREFIX}/bin
	@${CHMOD} +s ${PREFIX}/bin/Shutdown
	@${INSTALL_DATA} ${WRKSRC}/wmShutdown.xpm ${PREFIX}/share/wmShutdown/pixmaps/wmShutdown.xpm

post-install:
	@${ECHO} "===> Installed. Just type wmShutdown to use it"

.include <bsd.port.mk>
