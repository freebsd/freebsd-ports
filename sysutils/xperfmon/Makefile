# New ports collection makefile for:	xperfmon++ V1.40
# Version required:	1.1
# Date created:		14 March 97
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $Id: Makefile,v 1.17 1998/09/30 19:32:35 gj Exp $
#

DISTNAME=	xperfmon++
PKGNAME=	xperfmon++-2.0
CATEGORIES=     sysutils x11
# In Germany try this
MASTER_SITES=	ftp://proteus.arc.nasa.gov/pub/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller

DISTFILES=	xperfmon++v1.1.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

USE_IMAKE=	yes

pre-configure:
	if [ -e /usr/lib/libdevstat.a -o -e /usr/lib/aout/libdevstat.a ]; then \
		cd ${WRKSRC} ; \
		${MV} Imakefile Imakefile.in ; \
		${SED} -e "s:EXTRA_DEFINES=:EXTRA_DEFINES= -DHAVE_DEVSTAT:" Imakefile.in > Imakefile.i1 ; \
		${SED} -e "s:FreeBSDFLAGS=:FreeBSDFLAGS= -ldevstat:" Imakefile.i1 > Imakefile ; \
	fi

.include <bsd.port.mk>
