# New ports collection makefile for:	grdc-applet
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	grdc
PORTVERSION=	0.6.0
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-gnome/${PORTVERSION}
PKGNAMESUFFIX=	-applet
DISTNAME=	${PORTNAME}-gnome-${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A GNOME Desktop applet for GTK+/GNOME remote desktop client

RUN_DEPENDS=	grdc:${PORTSDIR}/net/grdc

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix glib20 gtk20 gnomepanel
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|"grdc"|"${LOCALBASE}/bin/grdc"|' \
		${WRKSRC}/src/grdcapplet.c

.include <bsd.port.mk>
