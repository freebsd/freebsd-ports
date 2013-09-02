# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#   $Id: Makefile,v 1.13 2006/10/08 01:57:16 killfill Exp $
#

PORTNAME=	gtk-sharp
PORTVERSION=	1.0.10
PORTREVISION=	21
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

LATEST_LINK=	gtk-sharp10
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USES=		perl5
USE_PERL5=	run
USE_GNOME=	gnomehack gtkhtml3 vte librsvg2 libgnomecanvas \
		libgnomeprintui libglade2 libgnomeui

USE_AUTOTOOLS=	libtool

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'
	@${REINPLACE_CMD} -e 's|enable_gda=yes|enable_gda=no|g ; \
		s|enable_gnomedb=yes|enable_gnomedb=no|g ; \
		s|libgtkhtml-3.8|libgtkhtml-3.14|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/glib/glue/slist.c ${WRKSRC}/glib/glue/list.c

pre-su-install:
	${MKDIR} ${LOCALBASE}/share/gapi

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
