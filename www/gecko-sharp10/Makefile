# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.14 2006/10/26 05:34:40 tmclau02 Exp $
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.6
PORTREVISION=	12
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gecko-sharp/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Mono bindings for embeding mozilla

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomehack gnometarget gtksharp10
LATEST_LINK=	gecko-sharp10
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
