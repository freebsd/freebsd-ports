# New ports collection makefile for:	x86info
# Date created:			26 Aug 2001
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	x86info
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org

ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${PREFIX}/bin

.include <bsd.port.mk>
