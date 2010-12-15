# New ports collection makefile for:    pdfgrep
# Date created:                         2010-11-28
# Whom:                                 Michael Ranner <michael@ranner.eu>
#
# $FreeBSD$
#

PORTNAME=	pdfgrep
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	michael@ranner.eu
COMMENT=	A tool to search text in PDF files

LIB_DEPENDS=	poppler.6:${PORTSDIR}/graphics/poppler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	poppler_CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/poppler"

PLIST_FILES=	bin/pdfgrep
MAN1=		pdfgrep.1

.include <bsd.port.mk>
