# New ports collection makefile for:	gicq
# Version required:		0.22
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.3 1998/12/11 02:30:32 flathill Exp $
#

DISTNAME=	gicq-0.22
CATEGORIES=	net
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10 \
		icq.0:${PORTSDIR}/devel/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		GTK_CONFIG="${X11BASE}/bin/gtk10-config"

.include <bsd.port.mk>
