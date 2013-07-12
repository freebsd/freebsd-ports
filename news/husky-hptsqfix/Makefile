# Created by: Max Khon
# $FreeBSD$

PORTNAME=	hptsqfix
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Fix message base

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi

MAN1=		hptsqfix.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/hptsqfix

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
