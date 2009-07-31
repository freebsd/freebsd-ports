# New ports collection makefile for:   kcube
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kcube
PORTVERSION=	0.61
PORTREVISION=	7
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.tuxed.de/kcube/download/

MAINTAINER=	michael@ranner.eu
COMMENT=	Another cpu load kicker applet for KDE

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
