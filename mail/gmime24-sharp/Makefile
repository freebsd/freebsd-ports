# New ports collection makefile for:		gmime2-sharp
# Date Created:					20050513
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.17 2006/10/26 18:37:29 tmclau02 Exp $
#

PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-24-sharp

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for gmime

LIB_DEPENDS=	gmime-2.4:${PORTSDIR}/mail/gmime24

MASTERDIR=	${.CURDIR}/../gmime24
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack gnometarget glib20 gtksharp20
CONFIGURE_ARGS=	--enable-mono=yes

LATEST_LINK=	gmime24-sharp

# Else we conflict with mail/gmime24
NOPORTDOCS=	yes

# Done in pre-configure because master port has a post-patch target already.
pre-configure:
	@${REINPLACE_CMD} -e 's|.@GMIME_VERSION@||g' \
		${WRKSRC}/mono/gmime-sharp.dll.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
