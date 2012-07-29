# ex:ts=8
# Ports collection makefile for:	netmap
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netmap
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NetMap%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make a graphical representation of the surrounding network

RUN_DEPENDS=	dotty:${PORTSDIR}/graphics/graphviz

USE_GMAKE=	yes

PLIST_FILES=	bin/makelist bin/netmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makelist/makelist ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netmap/netmap ${PREFIX}/bin

.include <bsd.port.mk>
