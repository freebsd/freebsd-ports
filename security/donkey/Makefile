# New ports collection makefile for:	donkey
# Version required:		0.5
# Date created:			17 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1996/09/19 11:33:48 max Exp $
#

DISTNAME=	donkey-0.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/Security/tool/donkey/

MAINTAINER=	max@FreeBSD.ORG

GNU_CONFIGURE=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}/obj/FreeBSD
PATCH_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_STRIP}

pre-configure:
	@(cd ${WRKDIR}/${DISTNAME}; ./setup FreeBSD)

.include <bsd.port.mk>
