# New ports collection makefile for:   wmnetmon
# Date created:		1 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmnetmon
PORTVERSION=	0.2p5
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.alvie.com/download/wmnetmon/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

BINMODE=        4755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmnetmon ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wmnetmonrc ${EXAMPLESDIR}

.include <bsd.port.mk>
