# Created by: Max Khon
# $FreeBSD$

PORTNAME=	hpucode
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Scan for UUE in message base

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAN1=		hpucode.1
MANCOMPRESSED=	yes
INFO=		hpucode

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
