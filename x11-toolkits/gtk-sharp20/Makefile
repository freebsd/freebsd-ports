# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#   $Id: Makefile,v 1.15 2006/02/05 03:18:12 tmclau02 Exp $
#

PORTNAME=	gtk-sharp
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://go-mono.com/sources/gtk-sharp-2.0/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodocer:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodocer:${PORTSDIR}/devel/monodoc

USE_X_PREFIX=	yes
LATEST_LINK=	gtk-sharp20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_GNOME=	gnomehack librsvg2 gnomepanel gtkhtml3 vte

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

pre-su-install:
	${MKDIR} ${LOCALBASE}/share/gapi-2.0

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
