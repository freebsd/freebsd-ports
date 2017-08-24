# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	pdfgrep
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://pdfgrep.org/download/

MAINTAINER=	michael@ranner.eu
COMMENT=	Tool to search text in PDF files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libpoppler.so:graphics/poppler \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

BROKEN_powerpc64=	fails to link: pdfgrep.cc: undefined reference to poppler::set_debug_error_function

GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/pdfgrep man/man1/pdfgrep.1.gz \
		share/bash-completion/completions/pdfgrep \
		share/zsh/site-functions/_pdfgrep

.include <bsd.port.mk>
