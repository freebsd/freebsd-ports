# New ports collection makefile for:    husky-smapi
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	smapi
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}_${PORTVERSION}-${PORTREVISION}

MAINTAINER=	fjoe@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
