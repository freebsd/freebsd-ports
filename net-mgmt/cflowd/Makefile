# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	cflowd
PORTVERSION=	2.1.b1
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.caida.org/tools/measurement/cflowd/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flow analysis tool used for analyzing Cisco's NetFlow switching

LIB_DEPENDS=	libArts.so:${PORTSDIR}/net-mgmt/arts++

GNU_CONFIGURE=	yes
USES=		bison gmake libtool:keepla
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --with-artspp=${LOCALBASE}

MANL=		cfdases.l cfdifmatrix.l cfdnets.l cfdnexthops.l \
		cfdportmatrix.l cfdprotos.l cfdtos.l flowdump.l flowwatch.l

OPTIONS_DEFINE=	FLOWSCAN
FLOWSCAN_DESC=	FlowScan patch

DEPRECATED=	Unmaintained 10 years, requires dozens of patches, unverifiable
EXPIRATION_DATE=2014-08-15

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1000000
BROKEN=		Fails with recent flex/clang/libc++, try net-mgmt/flow-tools
.endif

.if ${PORT_OPTIONS:MFLOWSCAN}
PATCH_SITES+=	http://net.doit.wisc.edu/~plonka/cflowd/
PATCHFILES+=	cflowd-${PORTVERSION:S|.|-|g}-djp.patch
.endif

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|fstream\.h|fstream|' -e 's|iomanip\.h|iomanip|' \
		-e 's|iostream\.h|iostream|' -e 's|strstream\.h|strstream|'

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample

.include <bsd.port.mk>
