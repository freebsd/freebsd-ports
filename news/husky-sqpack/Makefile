# New ports collection makefile for:    husky-sqpack
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	sqpack
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}_${PORTVERSION}-${PORTREVISION}

MAINTAINER=	fjoe@FreeBSD.org

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAN1=		sqpack.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
