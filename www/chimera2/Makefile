# New ports collection makefile for:	chimera
# Date created:         24 Nov 1997
# Whom:                 Bruce Gingery <bgingery@gtcs.com>
#
# $FreeBSD$
#

PORTNAME=	chimera
PORTVERSION=	2.0a19
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/WWW/chimera/ \
		ftp://ftp.uni-koeln.de/net/inet/WWW/

MAINTAINER=	bgingery@gtcs.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

MAN1=		chimera.1
USE_IMAKE=	yes

.include <bsd.port.mk>
