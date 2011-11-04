# New ports collection makefile for:	xjobs
# Date created:		28 October 2011
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#
#

PORTNAME=	xjobs
PORTVERSION=	20110730
CATEGORIES=	sysutils
MASTER_SITES=	http://www.maier-komor.de/xjobs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Utility reads job descriptions line by line and executes in parallel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/xjobs
MAN1=	xjobs.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
