# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $Id: Makefile,v 1.2 2005/02/27 04:28:41 mezz Exp $
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.go-mono.com/archive/${PORTVERSION}/

MAINTAINER=	coop9211@uidaho.edu
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
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.0|libgtkhtml-3.6|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
