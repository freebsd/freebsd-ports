# New ports collection makefile for: display
# Version required:	1.0
# Date created:		25 August 1997
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $Id$
#

DISTNAME=		display
PKGNAME=		display-1.0
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.uu.net/usenet/comp.sources.unix/volume8/
EXTRACT_SUFX=

MAINTAINER=		ports@FreeBSD.ORG

PATCHFILES=		display.pch.Z
PATCH_SITES=		${MASTER_SITES}

NO_WRKSUBDIR=		yes

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar
EXTRACT_CMD=		gunshar
EXTRACT_BEFORE_ARGS=

MAN1=			display.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/display ${PREFIX}/bin/display
	@${INSTALL_MAN} ${WRKSRC}/display.man ${PREFIX}/man/man1/display.1

.include <bsd.port.mk>
