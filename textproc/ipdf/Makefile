# ex:ts=8
# New ports collection makefile for:	ipdf
# Date created:			Nov 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ipdf
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates indexed pdf documents from text files

LIB_DEPENDS=	pdf.8:${PORTSDIR}/print/pdflib \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		ipdf.1
PLIST_FILES=	bin/ipdf

.include <bsd.port.mk>
