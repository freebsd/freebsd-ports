# New ports collection makefile for:	xperfmon++ V1.40
# Version required:	1.1
# Date created:		14 March 97
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $Id: Makefile,v 1.21 1998/11/21 07:27:41 steve Exp $
#

DISTNAME=	xperfmon++
PKGNAME=	xperfmon++-2.0
CATEGORIES=     sysutils
# In Germany try this
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/xperfmon/ \
		ftp://ftp.ibank.ru/pub/unix_src/benchmarks/
DISTFILES=	xperfmon++v1.1.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

USE_IMAKE=	yes
MAN1=		xperfmon++.1

pre-configure:
	if [ -e /usr/lib/libdevstat.a -o -e /usr/lib/aout/libdevstat.a ]; then \
		cd ${WRKSRC} ; \
		${MV} Imakefile Imakefile.in ; \
		${SED} -e "s:EXTRA_DEFINES=:EXTRA_DEFINES= -DHAVE_DEVSTAT:" Imakefile.in > Imakefile.i1 ; \
		${SED} -e "s:FreeBSDFLAGS=:FreeBSDFLAGS= -ldevstat:" Imakefile.i1 > Imakefile ; \
	fi

.include <bsd.port.mk>
