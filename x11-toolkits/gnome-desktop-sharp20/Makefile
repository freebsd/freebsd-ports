# Created by: pneumann@gmail.com
# $FreeBSD$

PORTNAME=	gnome-desktop-sharp
PORTVERSION=	2.26.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME desktop interfaces for the .NET runtime

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USES=		gmake mono perl5 pathfix pkgconfig tar:bzip2
USE_PERL5=	run
USE_GNOME=	gnomepanel gtkhtml3 gtksharp20 gnomesharp20 librsvg2 vte \
		libgnomeprintui gtksourceview2 gnomepanel libwnck

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include <bsd.port.mk>
