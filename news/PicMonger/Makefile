# New ports collection makefile for:	PicMonger
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PicMonger
PORTVERSION=	0.9.6
PORTREVISION=	7
CATEGORIES=	news graphics
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated USENET (NNTP) picture decoding client

LIB_DEPENDS=	gtkmm-1.2.2:${PORTSDIR}/x11-toolkits/gtkmm12
RUN_DEPENDS=	mpack:${PORTSDIR}/converters/mpack

USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
