# New ports collection makefile for:	gicq
# Version required:		0.22
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.1.1.1 1998/11/19 07:09:00 flathill Exp $
#

DISTNAME=	gicq-0.22
CATEGORIES=	net
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

MAINTAINER=	flathill@FreeBSD.ORG

BUILD_DEPENDS=	${LOCALBASE}/lib/libicq.a:${PORTSDIR}/devel/libicq
LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls

.include <bsd.port.mk>
