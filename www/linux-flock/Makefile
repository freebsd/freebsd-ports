# New ports collection makefile for:	linux-flock
# Date created:		30 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flock
PORTVERSION=	2.6.0
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www
MASTER_SITES=	http://dl01.flock.com/releases/${PORTVERSION}/

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The social web browser

DEPRECATED=	Flock 3 moves from Firefox to Chromium
BIN_NAME=	flock-browser
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_LDCONFIG=	yes
USE_BZIP2=	yes

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
