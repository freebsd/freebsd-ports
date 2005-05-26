# New ports collection makefile for:	915resolution
# Date created:				30 Apr 2004
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	915resolution
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://people.tecnik93.com/~acpi_perf/
DISTNAME=	${PORTNAME}

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	Resolution tool for Intel i915 video cards

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/915resolution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/915resolution ${PREFIX}/bin
	${BRANDELF} -t Linux ${PREFIX}/bin/915resolution

.include <bsd.port.mk>
