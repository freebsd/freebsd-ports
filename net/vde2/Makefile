# New ports collection makefile for:   vde2
# Date created:        20 January 2007
# Whom:                Philip M. Gollucci <pgollucci@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vde2
PORTVERSION=	2.1.6
CATEGORIES=	net
MASTER_SITES=	SF/vde/${PORTNAME}/${PORTVERSION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

MAKE_JOBS_SAFE=  yes

CONFLICTS=	vde-[0-9]*

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${PREFIX}

SHLIB_MAJOR=	2
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.include <bsd.port.pre.mk>

CFLAGS+=	${CPPFLAGS} -fPIC
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=		dpipe.1 slirpvde.1 unixterm.1 \
		vde_cryptcab.1 vde_plug.1 vde_plug2tap.1 \
		vde_switch.1 vdeq.1 vdetaplib.1 \
		wirefilter.1
MLINKS=		vdeq.1 vdeqemu.1
.include <bsd.port.post.mk>
