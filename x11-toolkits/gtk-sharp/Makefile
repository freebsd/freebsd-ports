# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	0.93
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_GNOME=	gnomehack libgnomedb gtkhtml3 vte librsvg2

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/parser/gapi.pl \
		${WRKSRC}/parser/gapi2xml.pl \
		${WRKSRC}/parser/gapi_pp.pl

pre-configure:
	@${FIND} ${WRKSRC} -name '*.config.in' | ${XARGS} ${REINPLACE_CMD} -e \
		's|@LIB_PREFIX@.*@LIB_SUFFIX@|.so|g'

.include <bsd.port.mk>
