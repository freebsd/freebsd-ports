# New ports collection makefile for:	netspeed_applet
# Date created:				08 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netspeed_applet
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	http://www.wh-hms.uni-ulm.de/~mfcn/shared/netspeed/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applet that shows how much network traffic occurs on an interface

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier intlhack gnomeprefix gnomehack gnomepanel
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"s/-D.*_DISABLE_DEPRECATED//g"

.include <bsd.port.mk>
