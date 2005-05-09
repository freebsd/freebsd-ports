# New ports collection makefile for:	most
# Date created:		31 May 1997
# Whom:			rhwang@bigpanda.com
#
# $FreeBSD$
#

PORTNAME=	most
PORTVERSION=	4.10.1
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/ \
		http://gd.tuwien.ac.at/editors/davis/most/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pager (like less) which has support for windows and binary files

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-mmap
MAN1=		most.1
CFLAGS+=	-O

.include <bsd.port.mk>
