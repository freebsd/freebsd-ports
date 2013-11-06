# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ntraceroute
PORTVERSION=	6.4.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_NETBSD} \
		http://mirrors.rit.edu/zi/
MASTER_SITE_SUBDIR=	traceroute-nanog
DISTNAME=	traceroute.c
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Ubiquitous network routing analysis tool

WRKSRC=		${WRKDIR}

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	sbin/${PORTNAME}

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} -lm \
	    ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
