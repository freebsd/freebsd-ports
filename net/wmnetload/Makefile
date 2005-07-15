# New ports collection makefile for:	wmnetload
# Date created:		6 February 2003
# Whom:		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	wmnetload
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	net windowmaker afterstep
MASTER_SITES=	ftp://truffula.com/pub/ \
				http://dl.fkb.wormulon.net/wmnetload/ \
				http://dl.kel.wormulon.net/wmnetload/

MAINTAINER=	hendrik@scholz.net
COMMENT=	Network load monitor dockapp

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmnetload
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmnetload/
.endif

.include <bsd.port.mk>
