# New ports collection makefile for:	mudix
# Date created:		26 Mar 2000
# Whom:			will
#
# $FreeBSD$
#

PORTNAME=	mudix
PORTVERSION=	3.5
CATEGORIES=	net
MASTER_SITES=	http://dwizardry.dhs.org/mudix/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS=	CC="${CC}" O_FLAGS="${CFLAGS}"
ALL_TARGET=	mudix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mudix ${PREFIX}/bin

.include <bsd.port.mk>
