# New ports collection makefile for:	gaspell
# Date created:				17th February 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaspell
PORTVERSION= 	0.29.1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://aspell.sourceforge.net/
DISTNAME=	${PORTNAME}-.29.1

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell

USE_NEWGCC=	yes
ALL_TARGET=	gaspell

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gaspell ${PREFIX}/bin

.include <bsd.port.mk>
