# New ports collection makefile for:   wmnetmon
# Date created:		1 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmnetmon
PORTVERSION=	0.2p5
CATEGORIES=	net windowmaker
# Master site is MIA for weeks now...
#MASTER_SITES=	ftp://neubula.utad.pt/pub/wmnetmon/
MASTER_SITES=	http://avdira.cc.duth.gr/~kkonstan/stuff/software/


MAINTAINER=	ports@FreeBSD.org

USE_XPM=	YES
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES

BINMODE=        4755

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmnetmon ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/wmnetmon
	@${INSTALL_DATA} ${WRKSRC}/wmnetmonrc ${PREFIX}/share/examples/wmnetmon

.include <bsd.port.mk>
