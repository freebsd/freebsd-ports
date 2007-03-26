# New ports collection makefile for:	linux-flock
# Date created:		30 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flock
PORTVERSION=	0.7.12
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www
MASTER_SITES=	http://ftp.acc.umu.se/mirror/%SUBDIR%/ \
		http://mirrors.ibiblio.org/pub/mirrors/%SUBDIR%/ \
		http://ftp.osuosl.org/pub/%SUBDIR%/ \
		http://www.gtlib.gatech.edu/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION:C/(((^|\.)[0-9]+){1,3}).*/\1/}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	The free web browser that makes it easier to share with your friends

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
