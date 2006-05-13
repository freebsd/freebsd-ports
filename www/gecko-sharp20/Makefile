# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.13 2005/12/04 23:26:32 tmclau02 Exp $
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.11
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/gecko-sharp-2.0/
DISTNAME=	gecko-sharp-2.0-${PORTVERSION}

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for embeding mozilla

BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools

USE_GECKO=	mozilla firefox
USE_GNOME=	gnometarget
LATEST_LINK=	gecko-sharp20
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
