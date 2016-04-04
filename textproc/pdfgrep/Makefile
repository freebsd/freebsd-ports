# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	pdfgrep
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://pdfgrep.org/download/

MAINTAINER=	michael@ranner.eu
COMMENT=	Tool to search text in PDF files

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler.so:graphics/poppler

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake pkgconfig
CONFIGURE_ARGS=	poppler_CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/poppler"

PLIST_FILES=	bin/pdfgrep man/man1/pdfgrep.1.gz \
		share/bash-completion/completions/pdfgrep \
		share/zsh/site-functions/_pdfgrep

.include <bsd.port.mk>
