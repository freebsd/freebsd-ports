# New ports collection makefile for: display
# Version required:	1.0
# Date created:		25 August 1997
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $Id: Makefile,v 1.5 1998/11/08 16:51:06 fenner Exp $
#

DISTNAME=		display
PKGNAME=		display-1.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_COMP_SOURCES}
MASTER_SITE_SUBDIR=	unix/volume8
EXTRACT_SUFX=		.Z

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		display.pch.Z

MAINTAINER=		ports@FreeBSD.ORG

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| gunshar -d ${WRKDIR}

MAN1=			display.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/display ${PREFIX}/bin/display
	@${INSTALL_MAN} ${WRKSRC}/display.man ${PREFIX}/man/man1/display.1

.include <bsd.port.mk>
