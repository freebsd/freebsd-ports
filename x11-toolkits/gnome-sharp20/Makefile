# Created by: Tom McLaughlin <tmclaugh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-sharp
PORTVERSION=	2.24.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GNOME interfaces for the .NET runtime

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool:keepla pathfix perl5 pkgconfig tar:bzip2
USE_PERL5=	run
USE_GNOME=	gnomepanel gtksharp20 librsvg2 vte libgnomeprintui libgnomeui
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
