# New ports collection makefile for:   wmshutdown
# Date created:        26 November 2002
# Whom:                nishida
#
# $FreeBSD$
#

PORTNAME=	wmShutdown
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dock application to shutdown or reboot

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_XORG=	xpm

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
