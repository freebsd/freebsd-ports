# New ports collection makefile for:	libwps
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwps
PORTVERSION=	0.1.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Microsoft file word processor format import filter library

LIB_DEPENDS=	wpd-0.8.8:${PORTSDIR}/textproc/libwpd

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack ltverhack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
