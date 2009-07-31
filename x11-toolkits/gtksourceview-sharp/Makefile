# New ports collection makefile for:    	gtksourceview-sharp
# Date created:         			20040821
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.30 2007/05/19 17:34:30 killfill Exp $
#

PORTNAME=	gtksourceview-sharp
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gtksourceview-sharp-2.0/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	gtksourview bindings for Mono.

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		monodoc:${PORTSDIR}/devel/mono-tools

USE_BZIP2=	yes
USE_GNOME=	gtksourceview gnomehack gtksharp20
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
