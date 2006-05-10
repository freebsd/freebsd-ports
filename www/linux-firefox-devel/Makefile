# New ports collection makefile for:	linux-firefox-devel
# Date created:		8 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	3.0.a${SNAPDATE:S/-/./g}
DISTVERSION=	3.0a1
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www linux
MASTER_SITE_SUBDIR=	${PORTNAME}/nightly/${SNAPDATE}-04-trunk
PKGNAMESUFFIX=		-devel
DIST_SUBDIR=		${PORTNAME}-${SNAPDATE}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

SNAPDATE=	2006-05-08
USE_BZIP2=	yes

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
