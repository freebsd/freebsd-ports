# Created by: Max Khon
# $FreeBSD$

PORTNAME=	hptkill
PORTVERSION=	1.10.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.10-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Area killing utility

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAN1=		hptkill.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/hptkill

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
