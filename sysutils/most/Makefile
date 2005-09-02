# New ports collection makefile for:	most
# Date created:				31 May 1997
# Whom:					rhwang@bigpanda.com
#
# $FreeBSD$
#

PORTNAME=	most
PORTVERSION=	4.10.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/ \
		http://gd.tuwien.ac.at/editors/davis/most/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A pager (like less) which has support for windows and binary files

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--enable-mmap

PLIST_FILES=	bin/most
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.doc most.rc
MAN1=		most.1

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
