# New ports collection makefile for:	zisofs-tools
# Date created:				24 Nov 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	zisofs-tools
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/fs/zisofs/

MAINTAINER=	chip-set@mail.ru
COMMENT=	User utilities for zisofs

USE_AUTOCONF_VER=	253
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

MAN1=		mkzftree.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES README INSTALL
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
