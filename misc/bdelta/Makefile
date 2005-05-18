# New ports collection makefile for:	bdelta
# Date created:		2005-05-18
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bdelta
PORTVERSION=	0.1.0
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	deltup

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An advanced delta creator, patcher, and library

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	bin/bdelta \
		bin/bpatch \
		lib/libbdelta.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bdelta ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bpatch ${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/libbdelta.so ${PREFIX}/lib

.include <bsd.port.mk>
