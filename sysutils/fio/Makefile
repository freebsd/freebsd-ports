# New ports collection makefile for:	fio
# Date created:         Jan.15, 2009
# Whom:                 luigi@FreeBSD.org
#
# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fio
PORTVERSION=	1.24
CATEGORIES=	sysutils
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	The program fio - flexible IO tester

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

SCRIPTS_ENV=	"SHELL=bash"
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKEFILE=	Makefile.FreeBSD

MAN1=	fio.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fio_generate_plots ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${PREFIX}/man/man1/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64-6
.endif
.endif

.include <bsd.port.post.mk>
