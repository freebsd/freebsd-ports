# New ports collection makefile for:	fio
# Date created:         Jan.15, 2009
# Whom:                 luigi@FreeBSD.org
#
# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fio
PORTVERSION=	1.44.3
CATEGORIES=	sysutils benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	The program fio - flexible IO tester

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.FreeBSD
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	GNUPLOT "Support for plotting graphs" off

MAN1=		fio.1 fio_generate_plots.1
PLIST_FILES=	bin/fio bin/fio_generate_plots

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fio ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fio_generate_plots ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fio.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/fio_generate_plots.1 ${PREFIX}/man/man1/

.include <bsd.port.pre.mk>

.if defined(WITH_GNUPLOT)
RUN_DEPENDS+=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot
.endif

.if ${OSVERSION} < 700000
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64-6
.endif
.endif

.include <bsd.port.post.mk>
