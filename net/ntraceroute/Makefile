# New ports collection makefile for:	ntraceroute
# Date created:		25 June 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ntraceroute
PORTVERSION=	6.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.login.com/pub/software/traceroute/beta/
DISTFILES=	traceroute_639.c
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network routing analysis tool

WRKSRC=		${WRKDIR}

NOMAN=		defined

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} -lm \
	    ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

do-install:
	${INSTALL} ${COPY} ${STRIP} -o root -g wheel -m 04555 \
	    ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
