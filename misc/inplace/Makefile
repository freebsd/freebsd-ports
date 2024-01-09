PORTNAME=	inplace
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		LOCAL/knu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to edit files in-place through given filter commands
WWW=		https://akinori.org/ #inplace

USES=		tar:bzip2 uidfix ruby shebangfix

MAKE_ARGS=	PREFIX="${PREFIX}" MANPREFIX="${PREFIX}/share"
MAKEFILE=	BSDmakefile

SHEBANG_FILES=	lib/inplace.rb

PLIST_FILES=	bin/inplace \
		share/man/man1/inplace.1.gz

test: build
	cd ${WRKSRC}; ${MAKE} test

.include <bsd.port.mk>
