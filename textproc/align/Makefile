# ex:ts=8
# New ports collection makefile for:	align
# Date created:			Oct 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	align
PORTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.indiana.edu/hyplan/kinzler/align/

MAINTAINER=	ports@FreeBSD.org

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/align ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/width ${PREFIX}/bin

.include <bsd.port.mk>
