# New ports collection makefile for:	donkey
# Date created:			17 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	donkey
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative for S/KEY's key command

GNU_CONFIGURE=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}/obj/FreeBSD
PATCH_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_STRIP}

pre-configure:
	@(cd ${WRKDIR}/${DISTNAME}; ./setup FreeBSD)

.include <bsd.port.mk>
