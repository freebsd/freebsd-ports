# New ports collection makefile for:	dadadodo
# Date created:			May 31, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	dadadodo
PORTVERSION=	1.03
CATEGORIES=	textproc
MASTER_SITES=	http://www.jwz.org/dadadodo/

MAINTAINER=	markp@FreeBSD.org

USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} -e "s/^(CC|CFLAGS).+//" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dadadodo ${PREFIX}/bin

.include <bsd.port.mk>
