# ex:ts=8
# New ports collection makefile for:	ipcalc
# Date created:			May 21, 2001
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	ipcalc
PORTVERSION=	0.33
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
DISTFILES=	ipcalc.pl
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
