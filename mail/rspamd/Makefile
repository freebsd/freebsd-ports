# $FreeBSD$

PORTNAME=	rspamd
PORTVERSION=	1.7.4
CATEGORIES=	mail

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libevent.so:devel/libevent \
		libluajit-5.1.so:lang/luajit \
		libicui18n.so:devel/icu
BUILD_DEPENDS=	ragel:devel/ragel
RUN_DEPENDS=	ca_root_nss>=3.*:security/ca_root_nss

CONFLICTS_INSTALL=	rspamd-devel

OPTIONS_DEFINE=		GPERF GD CGP TORCH_BLAS
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT_amd64=	TORCH
OPTIONS_SUB=	yes

OPTIONS_RADIO=	NEURAL_NETWORK
OPTIONS_RADIO_NEURAL_NETWORK=	FANN TORCH

CGP_DESC=		Install Communigate Pro(tm) helper
GD_DESC=		Enable libgd support for images fuzzy hashes
GPERF_DESC=		Google perf-tools profiling
HYPERSCAN_DESC=		Use hyperscan optimizations (amd64 only)
FANN_DESC=		Use Fast Artificial Neural Network Library (FANN)
TORCH_DESC=		Machine learning support using torch
TORCH_BLAS_DESC=	Build torch with OpenBLAS
TORCH_BLAS_IMPLIES=	TORCH

SUB_FILES=	pkg-message rspamd.newsyslog.conf.sample
PLIST_SUB+=	ETCDIR=etc/rspamd \
		RSPAMDVERSION=${PORTVERSION}
CMAKE_ARGS+=	-DCONFDIR=${PREFIX}/etc/rspamd \
		-DLOGDIR=/var/log/rspamd \
		-DDBDIR=/var/db/rspamd \
		-DRUNDIR=/var/run/rspamd \
		-DMANDIR=${MANPREFIX}/man \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DBUILD_PORT=yes \
		-DLIBDIR=${PREFIX}/lib/rspamd \
		-DNO_SHARED=ON

USES=		cmake:outsource pkgconfig perl5 \
		compiler:c11 sqlite ssl
USE_LDCONFIG=	yes
USE_PERL5=	build run

USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov

USE_RC_SUBR=	rspamd

GD_CMAKE_ON=	-DENABLE_GD=ON
GD_LIB_DEPENDS=	libgd.so:graphics/gd

GPERF_CMAKE_ON=	-DENABLE_GPERF_TOOLS=ON
GPERF_LIB_DEPENDS=	libprofiler.so:devel/google-perftools

HYPERSCAN_CMAKE_ON=	-DENABLE_HYPERSCAN=ON
HYPERSCAN_LIB_DEPENDS=	libhs.so:devel/hyperscan

FANN_CMAKE_ON=	-DENABLE_FANN=ON
FANN_LIB_DEPENDS=libfann.so:math/fann

TORCH_CMAKE_ON=	-DENABLE_TORCH=ON
TORCH_CMAKE_OFF=-DENABLE_TORCH=OFF

TORCH_BLAS_USES=	blaslapack:openblas
TORCH_BLAS_CMAKE_ON=	-DWITH_BLAS=open

CGP_RUN_DEPENDS+=	\
	p5-AnyEvent-HTTP>=0:www/p5-AnyEvent-HTTP \
	p5-AnyEvent>=0:devel/p5-AnyEvent \
	p5-EV>=0:devel/p5-EV \
	p5-JSON-XS>=0:converters/p5-JSON-XS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTORCH_BLAS}
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
	# No examples installed by the port
	${RMDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/rspamd.newsyslog.conf.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${LN} -s ${ETCDIR}/rspamd.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
post-install-CGP-on:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/cgp_rspamd.pl ${STAGEDIR}${PREFIX}/bin/rspamd-cgp-helper

.include <bsd.port.mk>
