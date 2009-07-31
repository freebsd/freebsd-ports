# New ports collection makefile for:	velocity
# Date created:		   19 November 2003
# Whom:				   Ryan
#
# $FreeBSD$
#

PORTNAME=	velocity
PORTVERSION=	0.1.0b
PORTREVISION=	12
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.jarrodkoehler.com/velocity/
DISTNAME=	velocity-0.1.0beta

MAINTAINER=	ryan.moe@fastfreedom.net
COMMENT=	GNOME file and desktop manager

WRKSRC=		${WRKDIR}/velocity-0.1.0
USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GNOME=	libgnomeui gnomedesktop librsvg2
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags libgnomeui-2.0`" \
		LIBS="`pkg-config --libs libgnomeui-2.0`"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile
.endif

BROKEN=	does not build with GNOME 2.26

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
