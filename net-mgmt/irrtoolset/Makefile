# New ports collection makefile for:	RAToolSet
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ratoolset
PORTVERSION=	3.5.8
CATEGORIES=	net tk82
MASTER_SITES=	ftp://ftp.isi.edu/ra/RAToolSet/
DISTNAME=	RAToolSet-3.5.8

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_BISON=	yes
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
