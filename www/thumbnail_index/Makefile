# New ports collection makefile for:	thumbnail_index
# Date created:		Aug 14, 2000
# Whom:			Yoshiro MIHIRA <sanpei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thumbnail_index
PORTVERSION=	1998.08.10
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thumbnail_index/
DISTNAME=	${PORTNAME}_10aug98

MAINTAINER=	sanpei@FreeBSD.org

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		pnmmerge:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		thumbnail_index.1

do-build:     # empty

.include <bsd.port.mk>
