# Created by: ijliao
# $FreeBSD$

PORTNAME=	libxdiff
PORTVERSION=	0.23
CATEGORIES=	textproc
MASTER_SITES=	http://www.xmailserver.org/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Create file differences/patches to both binary and text files

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

MAN3=		xdiff.3
PLIST_FILES=	include/xdiff.h lib/libxdiff.a lib/libxdiff.so \
		lib/libxdiff.so.0 lib/libxdiff.la
.include <bsd.port.mk>
