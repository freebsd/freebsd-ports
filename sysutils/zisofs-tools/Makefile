# New ports collection makefile for:	zisofs-tools
# Date created:				24 Nov 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	zisofs-tools
PORTVERSION=	1.0.6
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/fs/zisofs/

MAINTAINER=	chip-set@mail.ru
COMMENT=	User utilities for zisofs

PORTDOCS=	README CHANGES INSTALL

USE_AUTOCONF_VER=	259
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

MAN1=		mkzftree.1

PLIST_FILES=	bin/mkzftree

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
