# New ports collection makefile for:	RAToolSet
# Version required:			3.5.8
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	RAToolSet-3.5.8
PKGNAME=	ratoolset-3.5.8
CATEGORIES=	net tk82
MASTER_SITES=	ftp://ftp.isi.edu/ra/RAToolSet/

MAINTAINER=	jfitz@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	Yes
CONFIGURE_ENV=	TCL_TK_INCLUDE_DIR="${PREFIX}/include/tcl8.2:${PREFIX}/include/tk8.2" \
		TCL_TK_LIBRARY_DIR=${PREFIX}/lib \
		TCL_LIBRARY=${PREFIX}/lib/tcl8.2 \
		TK_LIBRARY=${PREFIX}/lib/tk8.2 \
		LD_TCL_TK_LIBS="-ltk82 -ltcl82"

MAN1=		CIDRAdvisor.1 aoe.1 pmatch.1 prpath.1 RtConfig.1 peval.1 \
		prcheck.1 roe.1
MAN8=		prtraceroute.8 relayd.8

ALL_TARGET=	depend all

.include <bsd.port.mk>
