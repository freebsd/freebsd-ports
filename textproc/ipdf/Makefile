# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipdf
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates indexed pdf documents from text files

LIB_DEPENDS=	pdf.6:${PORTSDIR}/print/pdflib \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ipdf.1
PLIST_FILES=	bin/ipdf

NO_STAGE=	yes
.include <bsd.port.mk>
