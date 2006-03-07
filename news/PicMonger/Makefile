# New ports collection makefile for:	PicMonger
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PicMonger
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	news graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=picmonger

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated USENET (NNTP) picture decoding client

LIB_DEPENDS=	gtkmm-1.2.2:${PORTSDIR}/x11-toolkits/gtk--
RUN_DEPENDS=	mpack:${PORTSDIR}/converters/mpack

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
