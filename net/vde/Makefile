# New ports collection makefile for:   vde
# Date created:        30 Janurary 2005
# Whom:                Craig Boston <craig@yekse.gank.org>
#
# $FreeBSD$
#

PORTNAME=	vde
PORTVERSION=	1.5.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	craig@yekse.gank.org
COMMENT=	User-mode virtual ethernet infrastructure

CONFLICTS=	vde2-[0-9]*

USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

CFLAGS+=	${CPPFLAGS} -fPIC
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=		dpipe.1 slirpvde.1 vdetaplib.1 vdeq.1 vde_plug.1 vde_switch.1

.include <bsd.port.post.mk>
