# $FreeBSD$

PORTNAME=	rspamd
PORTVERSION=	1.7.0.a2.20180302
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system dev version

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libevent.so:devel/libevent \
		libluajit-5.1.so:lang/luajit \
		libfann.so:math/fann \
		libicui18n.so:devel/icu
BUILD_DEPENDS=	ragel:devel/ragel

CONFLICTS_INSTALL=	rspamd

RSPAMD_VERSION=	1.7.0
USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov
GH_TAGNAME=	0fed6e67d

OPTIONS_DEFINE=		GPERF GD CGP TORCH
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_SUB=	yes

CGP_DESC=		Install Communigate Pro(tm) helper
GD_DESC=		Enable libgd support for images fuzzy hashes
GPERF_DESC=		Google perf-tools profiling
HYPERSCAN_DESC=		Use hyperscan optimizations (amd64 only)
TORCH_DESC=		Build with embedded Torch7

OPTIONS_DEFAULT=	TORCH

USE_RC_SUBR=	rspamd

SUB_FILES=	pkg-message rspamd.newsyslog.conf.sample
PLIST_SUB+=	ETCDIR=etc/rspamd \
		RSPAMDVERSION=${RSPAMD_VERSION}
CMAKE_ARGS+=	-DCONFDIR=${PREFIX}/etc/rspamd \
		-DLOGDIR=/var/log/rspamd \
		-DDBDIR=/var/db/rspamd \
		-DRUNDIR=/var/run/rspamd \
		-DMANDIR=${MANPREFIX}/man \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DBUILD_PORT=yes \
		-DLIBDIR=${PREFIX}/lib/rspamd \
		-DNO_SHARED=ON \
		-DDEBUG=ON \
		-DGIT_ID=${GH_TAGNAME} \
		-DENABLE_FANN=ON

USES=		cmake:outsource pkgconfig perl5 \
		compiler:c11 sqlite ssl
USE_LDCONFIG=	yes
USE_PERL5=	build run

USE_GNOME=	glib20
DEBUG_FLAGS=	-g -O0
WITH_DEBUG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGD}
 CMAKE_ARGS+=	-DENABLE_GD=ON
 LIB_DEPENDS+=	libgd.so:graphics/gd
.else
 CMAKE_ARGS+=	-DENABLE_GD=OFF
.endif

.if ${PORT_OPTIONS:MGPERF}
 CMAKE_ARGS+=	-DENABLE_GPERF_TOOLS=ON
 LIB_DEPENDS+=	libprofiler.so:devel/google-perftools
.endif

.if ${PORT_OPTIONS:MHYPERSCAN}
 CMAKE_ARGS+=		-DENABLE_HYPERSCAN=ON
 LIB_DEPENDS+=		libhs.so:devel/hyperscan
.endif

.if ${PORT_OPTIONS:MCGP}
 PLIST_SUB+=	CGP=""
 RUN_DEPENDS+=	\
	p5-AnyEvent-HTTP>=0:www/p5-AnyEvent-HTTP \
	p5-AnyEvent>=0:devel/p5-AnyEvent \
	p5-EV>=0:devel/p5-EV \
	p5-JSON-XS>=0:converters/p5-JSON-XS
.else
 PLIST_SUB+=	CGP="@comment "
.endif

.if ! ${PORT_OPTIONS:MTORCH}
 CMAKE_ARGS+=	-DENABLE_TORCH=OFF
.else
 LIB_DEPENDS+=	libopenblas.so:math/openblas
 USE_GCC=	yes
.endif

post-install:
	@${MKDIR} \
		${STAGEDIR}/var/log/rspamd \
		${STAGEDIR}/var/db/rspamd \
		${STAGEDIR}/var/run/rspamd
	# Linux specific
	${RM} ${STAGEDIR}/${ETCDIR}/rspamd.systemd.conf
	# No need, since rspamd.conf.sample is a same
	${RM} ${STAGEDIR}/${ETCDIR}/rspamd.sysvinit.conf
	${INSTALL_DATA} ${WRKDIR}/rspamd.newsyslog.conf.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${LN} -s ${ETCDIR}/rspamd.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
.if ${PORT_OPTIONS:MCGP}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/cgp_rspamd.pl ${STAGEDIR}${PREFIX}/bin/rspamd-cgp-helper
.endif

.include <bsd.port.mk>
