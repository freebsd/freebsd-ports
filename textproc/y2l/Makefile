# ex:ts=8
# New ports collection makefile for:	y2l
# Date created:			Feb 6, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	y2l
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

NO_BUILD=	yes

MAN1=	y2l.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/y2l ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/y2l.man ${MANPREFIX}/man/man1/y2l.1

.include <bsd.port.mk>
