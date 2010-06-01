# New ports collection makefile for:    gnome-sharp
# Date created:         		20070531
# Whom:                 		pneumann@gmail.com
#
# $FreeBSD$
#

PORTNAME=	gnome-desktop-sharp
PORTVERSION=	2.26.0
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME desktop interfaces for the .NET runtime

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
USE_GNOME=	gnomehack gnomepanel gtkhtml3 gtksharp20 gnomesharp20 librsvg2 vte \
		libgnomeprintui gtksourceview2 gnomepanel libwnck nautiluscdburner

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
