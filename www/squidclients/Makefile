# New ports collection makefile for:	squidclients
# Date created:		05 January 1999
# Whom:			Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	squidclients
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	http://www.cineca.it/~nico/binaries/
DISTNAME=	squidclients-1.6-freebsd.bin
EXTRACT_SUFX=

MAINTAINER=	demon@FreeBSD.org

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

do-install:
		@ ${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/squidclients

post-install:
		@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
