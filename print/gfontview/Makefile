# ex:ts=8
# New ports collection makefile for:	gfontview
# Date created:			Jul 9, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfontview
PORTVERSION=	0.5.0
PORTREVISION=	8
CATEGORIES=	print gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An outline font viewer

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib

USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1/freetype \
			  -I${LOCALBASE}/include" \
		SPOOLER="/usr/bin/lpr" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-fontdir="${LOCALBASE}/share/ghostscript/fonts" \
		--with-libungif

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXXFLAGS="-O2"|CXXFLAGS="$$CXXFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-I/usr/include/freetype||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
