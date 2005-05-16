# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $Id: Makefile,v 1.8 2005/04/15 04:51:40 tmclau02 Exp $
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	1.9.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp
PKGNAMESUFFIX=	-devel

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_GNOME=	gnomehack libgnomedb librsvg2 gnomepanel gtkhtml3 vte

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include <bsd.port.mk>
