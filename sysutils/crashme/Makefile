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

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A tool to test an operating system's robustness

USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		crashme.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crashme ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pddet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/crashme.man ${PREFIX}/man/man1/crashme.1

.include <bsd.port.mk>
