# ex:ts=8
# Ports collection makefile for:  vnconvert
# Date created:			  Fri Jan 05, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	vnconvert
PORTVERSION=	1.0
CATEGORIES=	vietnamese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	convert
EXTRACT_SUFX=	.tar

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Converts Vietnamese text files between popular formats

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=
MAN1=		vnconvert.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vnconvert ${PREFIX}/bin
	@${INSTALL_MAN} ${FILESDIR}/vnconvert.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
