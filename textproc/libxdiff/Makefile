# ex:ts=8
# Ports collection makefile for:	libxdiff
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libxdiff
PORTVERSION=	0.22
CATEGORIES=	textproc
MASTER_SITES=	http://www.xmailserver.org/

MAINTAINER=	ler@lerctr.org
COMMENT=	Create file differences/patches to both binary and text files

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

MAN3=		xdiff.3
PLIST_FILES=	include/xdiff.h lib/libxdiff.a lib/libxdiff.so \
		lib/libxdiff.so.0 lib/libxdiff.la
.include <bsd.port.mk>
