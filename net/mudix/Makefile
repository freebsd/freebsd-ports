# New ports collection makefile for:	mudix
# Date created:		26 Mar 2000
# Whom:			will
#
# $FreeBSD$
#

PORTNAME=	mudix
PORTVERSION=	3.4
CATEGORIES=	net
MASTER_SITES=	http://dwizardry.dhs.org/mudix/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS+=	ncurses.4:${PORTSDIR}/devel/ncurses

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	mudix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mudix ${PREFIX}/bin

.include <bsd.port.mk>
