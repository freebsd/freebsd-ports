# New ports collection makefile for:	RAToolSet
# Version required:			3.5.2
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.5 1998/02/12 15:47:38 hoek Exp $
#

DISTNAME=	RAToolSet-3.5.2
PKGNAME=	ratoolset-3.5.2
CATEGORIES=	net tk41
MASTER_SITES=	ftp://ftp.isi.edu/ra/RAToolSet/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11-toolkits/tk41

GNU_CONFIGURE=	Yes
CONFIGURE_ENV=	TCL_TK_INCLUDE_DIR="${PREFIX}/include/tcl7.5: \
			${PREFIX}/include/tk4.1" \
		TCL_TK_LIBRARY_DIR=${PREFIX}/lib \
		LD_TCL_TK_LIBS="-ltcl75 -ltk41"

MAN1=		CIDRAdvisor.1 aoe.1 pmatch.1 prpath.1 RtConfig.1 peval.1 \
		prcheck.1 roe.1
MAN8=		prtraceroute.8 relayd.8

ALL_TARGET=	depend all

.include <bsd.port.mk>
