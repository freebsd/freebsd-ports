# New ports collection makefile for:	most
# Date created:				31 May 1997
# Whom:					rhwang@bigpanda.com
#
# $FreeBSD$
#

PORTNAME=	most
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A pager (like less) which has support for windows and binary files

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-mmap
MAKE_JOBS_UNSAFE=	yes

LICENSE=	GPLv2

PLIST_FILES=	bin/most
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.doc most.rc
MAN1=		most.1

PORTSCOUT=	skipv:5.0.0a

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/jdmacros.h

.include <bsd.port.mk>
