# New ports collection makefile for:	gicq
# Version required:		0.22
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	gicq-0.22
PKGNAME=	gicq-0.22
CATEGORIES=	net
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

MAINTAINER=	flathill@FreeBSD.ORG

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls

BUILD_DEPENDS=	${LOCALBASE}/lib/libicq.a:${PORTSDIR}/devel/libicq \
		${X11BASE}/lib/libgtk.a:${PORTSDIR}/x11-toolkits/gtk

.include <bsd.port.mk>
