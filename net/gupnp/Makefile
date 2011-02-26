# New ports collection makefile for:	gupnp
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp
PORTVERSION=	0.13.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for UPnP devices

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gssdp-1.0:${PORTSDIR}/net/gssdp \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack libglade2 glib20
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|' \
		 ${WRKSRC}/tools/gupnp-binding-tool

.include <bsd.port.mk>
