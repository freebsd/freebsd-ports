# New ports collection makefile for:	wordnet
# Date created:		26 Feb 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	1.7
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.princeton.edu/pub/wordnet/${PORTVERSION}/ \
		ftp://ftp.ims.uni-stuttgart.de/pub/WordNet/${PORTVERSION}/
DISTFILES=	wn${PORTVERSION:S/.//}.unix.tar.gz

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

TCL_DVER=	8.3
SCRIPTS_ENV+=	TCL_DVER=${TCL_DVER}
MAKE_ENV+=	TCL_DVER=${TCL_DVER}
PLIST_SUB+=	TCL_DVER=${TCL_DVER} VER=${PORTVERSION}
# Parallel build is faster even on a single cpu machine:
MAKE_ARGS=	-j 2
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.for s in 1 3 5 7
MAN$s!=		${MAKE} -f ${FILESDIR}/man.Makefile -V MAN$s
.endfor
MANCOMPRESSED=	maybe

.include <bsd.port.post.mk>
