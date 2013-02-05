# Created by: ijliao
# $FreeBSD$

PORTNAME=	gfontview
PORTVERSION=	0.5.0
PORTREVISION=	10
CATEGORIES=	print gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An outline font viewer

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		gif.5:${PORTSDIR}/graphics/giflib

BROKEN=		does not build with giflib

USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SPOOLER="/usr/bin/lpr"
CPPFLAGS+=	-I${LOCALBASE}/include/freetype1/freetype \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-fontdir="${LOCALBASE}/share/ghostscript/fonts" \
		--with-libungif

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXXFLAGS="-O2"|CXXFLAGS="$$CXXFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-I/usr/include/freetype||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
