# New ports collection makefile for:	etherape
# Date created:				4 April 2001
# Whom: 				Holger Lamm <holger@eit.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	etherape
PORTVERSION=	0.5.7
CATEGORIES=	net gnome
MASTER_SITES=	http://prdownloads.sourceforge.net/etherape/ \
		ftp://etherape.sourceforge.net/pub/etherape/

MAINTAINER=	holger@eit.uni-kl.de

LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
MAN8=		etherape.8

.include <bsd.port.mk>
