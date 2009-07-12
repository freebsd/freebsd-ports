# New ports collection makefile for:	linux-flock
# Date created:		30 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flock
PORTVERSION=	2.5
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/%SUBDIR%/ \
		http://ftp.osuosl.org/pub/%SUBDIR%/ \
		http://saimei.acc.umu.se/mirror/%SUBDIR%/ \
		http://www.gtlib.gatech.edu/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The social web browser

BIN_NAME=	flock-browser
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_LDCONFIG=	yes
USE_BZIP2=	yes

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
