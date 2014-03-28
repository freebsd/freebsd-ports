# Created by: rhwang@bigpanda.com
# $FreeBSD$

PORTNAME=	most
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pager (like less) which has support for windows and binary files

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:${PORTSDIR}/devel/libslang2

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-mmap
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/most man/man1/most.1.gz
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.doc most.rc

PORTSCOUT=	skipv:5.0.0a

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
