# New ports collection makefile for:    	gtksourceview-sharp
# Date created:         			20040821
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.27 2006/10/26 05:36:01 tmclau02 Exp $
#

PORTNAME=	gtksourceview-sharp
PORTVERSION=	0.10
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://go-mono.com/sources/gtksourceview-sharp-2.0/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	gtksourview bindings for Mono.

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodoc:${PORTSDIR}/devel/mono-tools

USE_GNOME=	gtksourceview gnomehack gtksharp20
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
