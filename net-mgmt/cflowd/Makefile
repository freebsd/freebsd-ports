# New ports collection makefile for:	cflowd
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	cflowd
PORTVERSION=	2.1.b1
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.caida.org/pub/cflowd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flow analysis tool used for analyzing Cisco's NetFlow switching

LIB_DEPENDS=	Arts.0:${PORTSDIR}/net-mgmt/arts++

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_GCC=	2.95

CONFIGURE_ARGS=	--enable-shared --with-artspp=${LOCALBASE}

MANL=		cfdases.l cfdifmatrix.l cfdnets.l cfdnexthops.l \
		cfdportmatrix.l cfdprotos.l cfdtos.l flowdump.l flowwatch.l

OPTIONS=	FLOWSCAN "FlowScan patch" off

.include <bsd.port.pre.mk>

.if defined(WITH_FLOWSCAN)
PATCH_SITES+=	http://net.doit.wisc.edu/~plonka/cflowd/
PATCHFILES+=	cflowd-${PORTVERSION:S|.|-|g}-djp.patch
.endif

post-configure:
	${REINPLACE_CMD} -e 's/ gcc\* / gcc\* | g\+\+\* /g' ${WRKSRC}/libtool

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample

.include <bsd.port.post.mk>
