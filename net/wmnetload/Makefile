# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	wmnetload
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	net windowmaker afterstep
MASTER_SITES=	ftp://truffula.com/pub/ \
				http://dl.fkb.wormulon.net/wmnetload/ \
				http://dl.kel.wormulon.net/wmnetload/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Network load monitor dockapp

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

USE_BZIP2=	yes
USE_XORG=	xpm x11
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/wmnetload
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmnetload/
.endif

.include <bsd.port.mk>
