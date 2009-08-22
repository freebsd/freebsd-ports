# New ports collection makefile for:    husky-bsopack
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	bsopack
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/0.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Binkley-style outbound netmail packer

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAN1=		bsopack.1
MANCOMPRESSED=	yes
INFO=		bsopack

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
