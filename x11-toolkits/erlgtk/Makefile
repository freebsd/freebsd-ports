# New ports collection makefile for:	erlgtk
# Date Created:				2 June 2003
# Whom:				 	cpressey@catseye.mb.ca
#
# $FreeBSD$
#

PORTNAME=	erlgtk
PORTVERSION=	0.9.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	erlgtk
DIST_SUBDIR=	erlang

MAINTAINER=	chris_pressey@yahoo.ca
COMMENT=	GTK+ 1.2 binding for Erlang/OTP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

CONFIGURE_ARGS=	--without-gnome
CONFIGURE_WRKSRC=${WRKSRC}/config
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gdkpixbuf

.if !defined(DISPLAY)
IGNORE=		"must be built from within the X11 environment"
.endif

post-install:
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/erlgtk

.include <bsd.port.mk>
