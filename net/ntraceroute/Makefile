# New ports collection makefile for:	ntraceroute
# Date created:		25 June 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ntraceroute
PORTVERSION=	6.4.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.login.com/pub/software/traceroute/beta/ \
		http://gd.tuwien.ac.at/infosys/network/tools/traceroute/beta/
DISTNAME=	traceroute_640.c
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ubiquitous network routing analysis tool

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

NOMAN=		defined

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} -lm \
	    ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL} ${COPY} ${STRIP} -o root -g wheel -m 04555 \
	    ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
