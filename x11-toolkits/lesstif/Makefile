# Created by: 1wardd@airmail.net
# $FreeBSD$

PORTNAME=	lesstif
PORTVERSION=	0.95.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	API compatible clone of the Motif toolkit

LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2

CONFLICTS?=	open-motif-*

USE_BZIP2=	yes
USE_AUTOTOOLS=	automake:env autoconf libtool
USE_XORG=	sm ice xt xp xext x11 xextproto xrender xft
USE_LDCONFIG=	yes
LIBTOOLFILES=	aclocal.m4 test/aclocal.m4
CONFIGURE_ARGS+=	--enable-static --enable-shared --enable-production
CONFIGURE_ARGS+=	--disable-maintainer-mode
CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} \
		-e 's|LT_HAVE_FREETYPE|FINDXFT_HAVE_FREETYPE|g' \
		-e 's|LT_HAVE_XRENDER|FINDXFT_HAVE_XRENDER|g' \
		${WRKSRC}/acinclude.m4

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/autoconf/ac_find_motif.m4 \
		${STAGEDIR}${PREFIX}/share/aclocal

.include <bsd.port.mk>
