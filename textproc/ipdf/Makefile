# ex:ts=8
# New ports collection makefile for:	ipdf
# Date created:			Nov 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ipdf
PORTVERSION=	0.9.9
CATEGORIES=	textproc
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates indexed pdf documents from text files

LIB_DEPENDS=	pdf.5:${PORTSDIR}/print/pdflib \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ipdf.1

.include <bsd.port.mk>
