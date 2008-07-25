# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.19 2007/02/07 15:49:20 killfill Exp $
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gecko-sharp-2.0/
DISTNAME=	gecko-sharp-2.0-${PORTVERSION}

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Mono bindings for embeding mozilla

USE_GECKO=	firefox mozilla
USE_GNOME=	gnometarget gtksharp20
LATEST_LINK=	gecko-sharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
