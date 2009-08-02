# New ports collection makefile for:	cflowd
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	cflowd
PORTVERSION=	2.1.b1
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.caida.org/tools/measurement/cflowd/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flow analysis tool used for analyzing Cisco's NetFlow switching

LIB_DEPENDS=	Arts.0:${PORTSDIR}/net-mgmt/arts++

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --with-artspp=${LOCALBASE}

MANL=		cfdases.l cfdifmatrix.l cfdnets.l cfdnexthops.l \
		cfdportmatrix.l cfdprotos.l cfdtos.l flowdump.l flowwatch.l

OPTIONS=	FLOWSCAN "FlowScan patch" off

.include <bsd.port.pre.mk>

.if defined(WITH_FLOWSCAN)
PATCH_SITES+=	http://net.doit.wisc.edu/~plonka/cflowd/
PATCHFILES+=	cflowd-${PORTVERSION:S|.|-|g}-djp.patch
.endif

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS}	\
		${REINPLACE_CMD} -e 's|iostream.h>|iostream>|;s|strstream.h|sstream|'
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e '/^LIBTOOL =/s^\$$(top_builddir)/libtool^${LIBTOOL}^'	\
		-e '/LIBTOOL/ { ;\
			N ;\
			/ -o / s|$${LIBTOOL} $${CXX}|$${LIBTOOL} --mode=link $${CXX}| ;\
			P ;\
			D ;\
		}';
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|$${LIBTOOL} $$(CXX)|$${LIBTOOL} --mode=compile $$(CXX)|'		\
		-e 's|$${LIBTOOL} $${CXX}|$${LIBTOOL} --mode=compile $${CXX}|'		\
		-e 's|$${LIBTOOL} \.\.|$${LIBTOOL} --mode=install ..|'

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample

.include <bsd.port.post.mk>
