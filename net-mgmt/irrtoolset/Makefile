# New ports collection makefile for:	IRRToolSet
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irrtoolset
PORTVERSION=	4.7.3
PORTREVISION=	1
CATEGORIES=	net-mgmt tk82
MASTER_SITES=	ftp://ftp.ripe.net/tools/IRRToolSet/IRRToolSet-${PORTVERSION}/
DISTNAME=	IRRToolSet-${PORTVERSION}

MAINTAINER=	oberman@es.net
COMMENT=	A suite of routing policy tools to interact with the IRR

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_BISON=	yes
USE_GMAKE=	yes
USE_GCC=	2.95
GNU_CONFIGURE=	Yes
CONFIGURE_ENV=	TCL_TK_INCLUDE_DIR="${PREFIX}/include/tcl8.3:${PREFIX}/include/tk8.3" \
		TCL_TK_LIBRARY_DIR=${PREFIX}/lib \
		TCL_LIBRARY=${PREFIX}/lib/tcl8.3 \
		TK_LIBRARY=${PREFIX}/lib/tk8.3 \
		LD_TCL_TK_LIBS="-ltk83 -ltcl83"

MAN1=		CIDRAdvisor.1 Errors.1 RtConfig.1 aoe.1 peval.1 prpath.1 \
		prtraceroute.1 roe.1 rpslcheck.1
MAN3=		librpsl.3

.include <bsd.port.pre.mk>

post-patch:
	@${SED} -i.orig -e 's|#include <malloc.h>|/* #include <malloc.h> */|' \
		${WRKSRC}/src/irr/birdwhoisc.cc

aLL_TARGET=	depend all

.include <bsd.port.post.mk>
