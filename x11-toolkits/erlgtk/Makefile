# New ports collection makefile for:	erlgtk
# Date Created:				2 June 2003
# Whom:				 	cpressey@catseye.mb.ca
#
# $FreeBSD$
#

PORTNAME=	erlgtk
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	erlgtk
DIST_SUBDIR=	erlang

MAINTAINER=	chris_pressey@yahoo.ca
COMMENT=	GTK+ binding for Erlang/OTP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

CONFIGURE_WRKSRC=${WRKSRC}/config
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

.if defined(WITH_GTK2)
PKGNAMESUFFIX=	-gtk2
CONFIGURE_ARGS=	--without-gnome --with-gtk=2.0
USE_GNOME=	gtk20 gdkpixbuf
.else
CONFIGURE_ARGS=	--without-gnome --with-gtk=1.2
USE_GNOME=	gtk12 gdkpixbuf
.endif

.if !defined(DISPLAY)
IGNORE=		"must be built from within the X11 environment"
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "The following build options are available:"
	@${ECHO} ""
	@${ECHO} "      WITH_GTK2=yes      Build erlgtk with GTK+ 2.x binding"
	@${ECHO} ""

post-install:
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/erlgtk

.include <bsd.port.mk>
