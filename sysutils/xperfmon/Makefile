# New ports collection makefile for:	xperfmon++
# Date created:		14 March 97
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	xperfmon++
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/xperfmon/ \
		ftp://ftp.ibank.ru/pub/unix_src/benchmarks/
DISTNAME=	xperfmon++v1.1
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	A graphical X11 system performance monitor

USE_IMAKE=	yes
MAN1=		xperfmon++.1
WRKSRC=		${WRKDIR}/xperfmon++

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
IGNORE=		5.X or newer systems should use xperfmon3
.endif

pre-configure:
	if [ -e /usr/lib/libdevstat.a -o -e /usr/lib/aout/libdevstat.a ]; then \
		cd ${WRKSRC} ; \
		${MV} Imakefile Imakefile.in ; \
		${SED} -e "s:EXTRA_DEFINES=:EXTRA_DEFINES= -DHAVE_DEVSTAT:" Imakefile.in > Imakefile.i1 ; \
		${SED} -e "s:FreeBSDFLAGS=:FreeBSDFLAGS= -ldevstat:" Imakefile.i1 > Imakefile ; \
	fi

.include <bsd.port.post.mk>
