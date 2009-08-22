# New ports collection makefile for:    husky-hpucode
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	hpucode
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Scan for UUE in message base

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAN1=		hpucode.1
MANCOMPRESSED=	yes
INFO=		hpucode

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
