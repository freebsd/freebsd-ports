# Created by: rhwang@bigpanda.com
# $FreeBSD$

PORTNAME=	most
PORTVERSION=	5.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.jedsoft.org/releases/most/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pager (like less) which has support for windows and binary files

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-mmap

PLIST_FILES=	bin/most man/man1/most.1.gz
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.rc most.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
