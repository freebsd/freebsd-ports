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

LIB_DEPENDS=	libdockapp.so:${PORTSDIR}/x11-wm/libdockapp

USES=		tar:bzip2
USE_XORG=	xpm x11
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
