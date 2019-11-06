# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	wmnetload
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	net windowmaker afterstep
MASTER_SITES=	ftp://truffula.com/pub/ \
		http://dl.fkb.wormulon.net/wmnetload/ \
		http://dl.kel.wormulon.net/wmnetload/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Network load monitor dockapp

BROKEN=		unfetchable

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		tar:bzip2 xorg
USE_XORG=	xpm x11
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
