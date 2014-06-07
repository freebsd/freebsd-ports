# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	pdfgrep
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	michael@ranner.eu
COMMENT=	Tool to search text in PDF files

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
CONFIGURE_ARGS=	poppler_CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/poppler"

PLIST_FILES=	bin/pdfgrep man/man1/pdfgrep.1.gz

.include <bsd.port.mk>
