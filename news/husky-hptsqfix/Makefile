# New ports collection makefile for:    husky-hptsqfix
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	hptsqfix
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Fix message base

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi

MAN1=		hptsqfix.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/hptsqfix

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
