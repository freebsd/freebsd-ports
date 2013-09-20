# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

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

USE_GNOME=	gnomehack glib20 gtksharp20
CONFIGURE_ARGS=	--enable-mono=yes

LATEST_LINK=	gmime2-sharp

# Else we conflict with mail/gmime2
NOPORTDOCS=	yes

# Done in pre-configure because master port has a post-patch target already.
NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e 's|.@GMIME_VERSION@||g' \
		${WRKSRC}/mono/gmime-sharp.dll.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
