# ex:ts=8
# New ports collection makefile for:	ipdf
# Date created:			Nov 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ipdf
PORTVERSION=	0.9.7
CATEGORIES=	textproc
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Creates indexed pdf documents from text files

LIB_DEPENDS=	pdf:${PORTSDIR}/print/pdflib \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	ipdf.1

.include <bsd.port.mk>
