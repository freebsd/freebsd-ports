# New ports collection makefile for:		gmime2-sharp
# Date Created:					20050513
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.15 2005/11/23 01:39:36 tmclau02 Exp $
#

PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-sharp

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for gmime

LIB_DEPENDS=	gmime-2.0.4:${PORTSDIR}/mail/gmime2
BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20

MASTERDIR=	${.CURDIR}/../gmime2
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack gnometarget glib20
CONFIGURE_ARGS=	--enable-mono=yes

LATEST_LINK=	gmime2-sharp

# Else we conflict with mail/gmime2
NOPORTDOCS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|.@GMIME_VERSION@||g' \
		${WRKSRC}/mono/gmime-sharp.dll.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
