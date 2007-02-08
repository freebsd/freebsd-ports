# New ports collection makefile for:	fntsample
# Date created:		22 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fntsample
PORTVERSION=	2.2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF http://unicode.org/Public/5.0.0/ucd/:unidata
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Blocks.txt:unidata
EXTRACT_ONLY=	${DISTFILES:M*gz}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Show Unicode coverage of a font

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GNOME=	glib20 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-extract:
	@${CP} ${_DISTDIR}/Blocks.txt ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/unicode|${WRKSRC}|' ${WRKSRC}/configure

.include <bsd.port.mk>
