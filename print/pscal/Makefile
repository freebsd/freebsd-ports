# New ports collection makefile for:	pscal
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	pscal
PORTVERSION=	1.15
CATEGORIES=	print
MASTER_SITES=	http://www.panix.com/~mbh/pscal/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A utility for generating Postscript calendars

NO_BUILD=	yes
PLIST_FILES=	bin/pscal

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pscal ${PREFIX}/bin

.include <bsd.port.mk>
