# New ports collection makefile for:	squidtimes
# Date created:		31 January 1999
# Whom:			Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	squidtimes
PORTVERSION=	1.12
CATEGORIES=	www
MASTER_SITES=	http://www.cineca.it/~nico/binaries/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	billf
DISTNAME=	squidtimes-1.12-freebsd.bin
EXTRACT_SUFX=

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Generates a report of average transfer times of Squid cache

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
PLIST_FILES=	bin/squidtimes

do-install:
		@ ${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/squidtimes

post-install:
		@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
