# New ports collection makefile for:	crashme
# Date created:			Apr 1, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	crashme
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris
DISTNAME=	crashme
EXTRACT_SUFX=	.tgz

MAINTAINER=	gjc@alum.mit.edu
COMMENT=	A tool to test an operating system's robustness

# according to license.rtf, and using the most restrictive one:
LICENSE=	LGPL21

USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		crashme.1
PLIST_FILES=	bin/crashme bin/pddet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crashme ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pddet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/crashme.man ${PREFIX}/man/man1/crashme.1

.include <bsd.port.mk>
