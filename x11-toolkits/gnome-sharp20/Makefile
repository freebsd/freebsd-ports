# New ports collection makefile for:    gnome-sharp
# Date created:         		20061025
# Whom:                 		Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-sharp
PORTVERSION=	2.24.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME interfaces for the .NET runtime

LATEST_LINK=	gnome-sharp20
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USES=		perl5
USE_PERL5=	run
USE_GNOME=	gnomehack gnomepanel gtksharp20 librsvg2 vte libgnomeprintui \
		libgnomeui
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
