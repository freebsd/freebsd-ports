# New ports collection makefile for:	XML::LibRSVG
# Date created:		20 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-LibRSVG
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	textproc graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Interface to GNOME's librsvg

LIB_DEPENDS=	rsvg.1:${PORTSDIR}/graphics/librsvg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png \
		art_lgpl.5:${PORTSDIR}/graphics/libart

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	INC='-I${LOCALBASE}/include' LIBS='-L${LOCALBASE}/lib'
USE_GNOME=	gdkpixbuf

MAN3=		XML::LibRSVG.3

.include <bsd.port.mk>
