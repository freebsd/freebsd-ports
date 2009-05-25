# New ports collection makefile for:   usbrh
# Date created:        2008-01-06
# Whom:                sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	usbrh
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.nk-home.net/~aoyama/usbrh/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sanpei

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Reads temperatures and humidity from a Strawberry Linux USB-RH

MAN1=		usbrh.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/usbrh

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
