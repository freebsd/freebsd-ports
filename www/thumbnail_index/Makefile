# New ports collection makefile for:	thumbnail_index
# Date created:		Aug 14, 2000
# Whom:			Yoshiro MIHIRA <sanpei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thumbnail_index
PORTVERSION=	1998.08.10
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thumbnail_index/
DISTNAME=	${PORTNAME}_10aug1998

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Make an HTML index file for a bunch of images

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		pnmscale:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		thumbnail_index.1

NO_BUILD=	yes

.include <bsd.port.mk>
