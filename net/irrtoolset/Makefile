# New ports collection makefile for:	RAToolSet
# Version required:			4.5.0
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	RAToolSet-4.5.0
PKGNAME=	ratoolset-4.5.0
CATEGORIES=	net tk82
MASTER_SITES=	ftp://ftp.isi.edu/ra/RAToolSet/

MAINTAINER=	jfitz@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_NEWGCC=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	TCL_TK_INCLUDE_DIR="${LOCALBASE}/include/tcl8.2:${LOCALBASE}/include/tk8.2" \
		TCL_TK_LIBRARY_DIR=${LOCALBASE}/lib \
		TCL_LIBRARY=${LOCALBASE}/lib/tcl8.2 \
		TK_LIBRARY=${LOCALBASE}/lib/tk8.2 \
		LD_TCL_TK_LIBS="-ltk82 -ltcl82"

MAN1=		CIDRAdvisor.1 RtConfig.1 aoe.1 peval.1 prpath.1 \
		prtraceroute.1 roe.1 rpslcheck.1
MAN8=		prtraceroute.8

ALL_TARGET=	depend all

.include <bsd.port.mk>
