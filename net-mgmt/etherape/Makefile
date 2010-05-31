# New ports collection makefile for:	etherape
# Date created:				4 April 2001
# Whom: 				Holger Lamm <holger@eit.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	etherape
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	net-mgmt gnome
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A graphical network traffic visualization tool for gnome

USE_GNOME=	libglade2 libgnomeui gnomehack gnomeprefix
USE_GMAKE=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		etherape.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.mk>
