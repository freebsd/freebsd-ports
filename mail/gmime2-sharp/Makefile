# New ports collection makefile for:		gmime2-sharp
# Date Created:					20050513
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.9 2005/09/25 00:56:46 tmclau02 Exp $
#

PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-sharp

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for gmime

LIB_DEPENDS=	gmime-2.0.3:${PORTSDIR}/mail/gmime2
BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20

MASTERDIR=	${.CURDIR}/../gmime2
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack gnometarget glib20
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-mono=yes

# Else we conflict with mail/gmime2
NOPORTDOCS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|.@GMIME_VERSION@||g' \
		${WRKSRC}/mono/gmime-sharp.dll.config.in
	@${REINPLACE_CMD} -e 's|libglib-2.0.so.0|libglib-2.0.so|g' \
		${WRKSRC}/mono/ObjectStream.cs ${WRKSRC}/mono/Object.custom

.include "${MASTERDIR}/Makefile"
