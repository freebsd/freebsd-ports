# New ports collection makefile for: copytape
# Version required:	1.0
# Date created:		23 October 1998
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $Id$
#

DISTNAME=		copytape
PKGNAME=		copytape-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.uu.net/usenet/comp.sources.unix/volume10/
EXTRACT_SUFX=		.Z

MAINTAINER=		ports@FreeBSD.ORG

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar

NO_WRKSUBDIR=		yes

EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| gunshar -d ${WRKDIR}

MAN1=			copytape.1
MAN5=			copytape.5

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/copytape ${PREFIX}/bin/copytape
	@${INSTALL_MAN} ${WRKSRC}/copytape.1 ${PREFIX}/man/man1/copytape.1
	@${INSTALL_MAN} ${WRKSRC}/copytape.5 ${PREFIX}/man/man5/copytape.5

.include <bsd.port.mk>
