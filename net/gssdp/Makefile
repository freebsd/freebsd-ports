# New ports collection makefile for:	gssdp
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gssdp
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sites/all/files/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for UPnP devices

LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack libglade2 glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
