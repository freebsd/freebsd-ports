# New ports collection makefile for:	cflowd
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	cflowd
PORTVERSION=	2.1.b1
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.caida.org/pub/cflowd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

.if defined(CFLOWD_FLOWSCAN_PATCH)
PATCH_SITES=	http://net.doit.wisc.edu/~plonka/cflowd/
PATCHFILES=	cflowd-2-1-b1-djp.patch
.endif

MAINTAINER=	ler@lerctr.org
COMMENT=	Flow analysis tool used for analyzing Cisco's NetFlow switching

BUILD_DEPENDS=	${LOCALBASE}/lib/libArts.a:${PORTSDIR}/net/arts++

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes

CONFIGURE_ARGS+=--enable-shared --with-artspp=${PREFIX}

MANL=		cfdases.l cfdifmatrix.l cfdnets.l cfdnexthops.l \
		cfdportmatrix.l cfdprotos.l cfdtos.l flowdump.l flowwatch.l

.if !defined(CFLOWD_FLOWSCAN_PATCH)
pre-everything::
	@${ECHO} "you can compile cflowd with patches for FlowScan by typing:"
	@${ECHO} "make CFLOWD_FLOWSCAN_PATCH=yes"
.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample

.include <bsd.port.mk>
