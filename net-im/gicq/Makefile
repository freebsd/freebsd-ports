# New ports collection makefile for:	gicq
# Version required:			0.33
# Date Created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $Id: Makefile,v 1.6 1999/04/06 12:02:41 flathill Exp $
#

DISTNAME=	gicq-0.33
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/	\
		http://www.nectar.com/distfiles/

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12	\
		icq.0:${PORTSDIR}/net/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.include <bsd.port.mk>
