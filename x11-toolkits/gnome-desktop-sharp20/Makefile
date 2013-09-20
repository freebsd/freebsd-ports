# Created by: pneumann@gmail.com
# $FreeBSD$

PORTNAME=	gnome-desktop-sharp
PORTVERSION=	2.26.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME desktop interfaces for the .NET runtime

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake perl5 pkgconfig
USE_PERL5=	run
USE_GNOME=	gnomehack gnomepanel gtkhtml3 gtksharp20 gnomesharp20 librsvg2 vte \
		libgnomeprintui gtksourceview2 gnomepanel libwnck nautiluscdburner

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
