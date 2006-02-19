# New ports collection makefile for:    	gtksourceview-sharp
# Date created:         			20040821
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.24 2006/02/01 23:02:05 tmclau02 Exp $
#

PORTNAME=	gtksourceview-sharp
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://go-mono.com/sources/gtksourceview-sharp-2.0/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	gtksourview bindings for Mono

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools

USE_GNOME=	gtksourceview gnomehack
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
