# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $Id: Makefile,v 1.15 2005/03/26 22:41:35 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	1.0.8
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

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
USE_GNOME=	gnomehack libgnomedb gtkhtml3 vte librsvg2

MAKE_ENV=MONO_SHARED_DIR=${WRKDIR}

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include <bsd.port.mk>
