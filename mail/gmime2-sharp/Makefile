# New ports collection makefile for:		gmime2-sharp
# Date Created:					20050513
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.17 2006/10/26 18:37:29 tmclau02 Exp $
#

PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-sharp

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for gmime

IGNORE=		try to install weaked-named assembly into the GAC.

LIB_DEPENDS=	gmime-2.0.4:${PORTSDIR}/mail/gmime2

MASTERDIR=	${.CURDIR}/../gmime2
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack gnometarget glib20 gtksharp20
CONFIGURE_ARGS=	--enable-mono=yes

LATEST_LINK=	gmime2-sharp

# Else we conflict with mail/gmime2
NOPORTDOCS=	yes

# Done in pre-configure because master port has a post-patch target already.
pre-configure:
	@${REINPLACE_CMD} -e 's|.@GMIME_VERSION@||g' \
		${WRKSRC}/mono/gmime-sharp.dll.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
