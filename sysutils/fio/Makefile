# New ports collection makefile for:	fio
# Date created:         Jan.15, 2009
# Whom:                 luigi@FreeBSD.org
#
# Maintainers:		Bruce Cran <brucec@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fio
PORTVERSION=	2.0.13
CATEGORIES=	sysutils benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	brucec@FreeBSD.org
COMMENT=	FIO - flexible IO tester

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS=	GNUPLOT "Support for plotting graphs" off

MAN1=		fio.1 fio_generate_plots.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fio_generate_plots ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/fio_generate_plots.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GNUPLOT)
BUILD_DEPENDS+=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot
.endif

.include <bsd.port.post.mk>
