# New ports collection makefile for: copytape
# Date created:		23 October 1998
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=		copytape
PORTVERSION=		1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_COMP_SOURCES}
MASTER_SITE_SUBDIR=	unix/volume10
DISTNAME=		copytape
EXTRACT_SUFX=		.Z

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A program that is used to duplicate magtapes

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar

NO_WRKSUBDIR=		yes

EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| gunshar -d ${WRKDIR}

MAN1=			copytape.1
MAN5=			copytape.5
PLIST_FILES=		bin/copytape

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/copytape ${PREFIX}/bin/copytape
	@${INSTALL_MAN} ${WRKSRC}/copytape.1 ${PREFIX}/man/man1/copytape.1
	@${INSTALL_MAN} ${WRKSRC}/copytape.5 ${PREFIX}/man/man5/copytape.5

.include <bsd.port.mk>
