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

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-mmap
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/most
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.doc most.rc
MAN1=		most.1

PORTSCOUT=	skipv:5.0.0a

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
