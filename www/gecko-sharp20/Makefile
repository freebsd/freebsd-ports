# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.17 2006/10/26 05:35:10 tmclau02 Exp $
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.11
PORTREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/gecko-sharp-2.0/
DISTNAME=	gecko-sharp-2.0-${PORTVERSION}

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for embeding mozilla

USE_GECKO=	firefox mozilla
USE_GNOME=	gnometarget gtksharp20
LATEST_LINK=	gecko-sharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

# configure was never updated after the monodoc/mono-tools split so it only
# installs doc when mono-tools is installed though it only needs monbodoc.
# Set MONODOC to a program contained in the monodoc port to fix this.
CONFIGURE_ENV+=	MONODOC="${LOCALBASE}/bin/monodocer"

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
