# New ports collection makefile for: archivemount
# Date created: 2008-06-20
# Whom: Evgeny Zhirnov <jirnov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	archivemount
PORTVERSION=	0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cybernoia.de/software/archivemount/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Mount archives with FUSE

BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

PLIST_FILES=	bin/archivemount

NO_INSTALL_MANPAGES=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GCC=	4.2+

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/archivemount ${PREFIX}/bin

.include <bsd.port.mk>
