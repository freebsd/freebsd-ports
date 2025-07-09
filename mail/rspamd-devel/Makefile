PORTNAME=	rspamd
PORTVERSION=	3.11.a1.20241020
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system dev version
WWW=		https://rspamd.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	ragel:devel/ragel
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libpcre2-8.so:devel/pcre2 \
		libsodium.so:security/libsodium
RUN_DEPENDS=	ca_root_nss>=3.*:security/ca_root_nss

USES=		cmake compiler:c++20-lang cpe gnome perl5 pkgconfig sqlite ssl
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_TAGNAME=	1ad4dba75
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_RC_SUBR=	rspamd

CMAKE_ARGS+=	-DBUILD_PORT=yes \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCONFDIR=${PREFIX}/etc/rspamd \
		-DDBDIR=/var/db/rspamd \
		-DDEBUG=ON \
		-DGIT_ID=${GH_TAGNAME} \
		-DLIBDIR=${PREFIX}/lib/rspamd \
		-DLOGDIR=/var/log/rspamd \
		-DRUNDIR=/var/run/rspamd

DEBUG_FLAGS=	-g -O0

CONFLICTS_INSTALL=	rspamd

SUB_FILES=	pkg-message rspamd.newsyslog.conf.sample

USERS=		rspamd
GROUPS=		rspamd

PLIST_SUB+=	ETCDIR=etc/rspamd \
		RSPAMDVERSION=${PORTVERSION:C/^([^.]+\.[^.]+).*/\1/}

OPTIONS_DEFINE=	BLAS CGP GPERF LUAJIT
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT_amd64=	LUAJIT
OPTIONS_DEFAULT_armv7=	LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_powerpc=	LUAJIT
OPTIONS_DEFAULT_powerpc64=	LUAJIT
OPTIONS_DEFAULT_powerpc64le=	LUAJIT
OPTIONS_SUB=	yes

BLAS_DESC=	Use OpenBLAS to accelerate KANN
CGP_DESC=	Install Communigate Pro(tm) helper
GPERF_DESC=	Google perf-tools profiling
HYPERSCAN_DESC=	Use hyperscan optimizations (amd64 only)
LUAJIT_DESC=	Use LuaJIT instead of standard Lua

BLAS_LIB_DEPENDS=	libblis.so:math/blis \
			liblapack.so:math/lapack
BLAS_USES=		blaslapack:openblas
BLAS_CMAKE_ON=		-DENABLE_BLAS=ON

CGP_RUN_DEPENDS+=	p5-AnyEvent-HTTP>=0:www/p5-AnyEvent-HTTP \
			p5-AnyEvent>=0:devel/p5-AnyEvent \
			p5-EV>=0:devel/p5-EV \
			p5-JSON-XS>=0:converters/p5-JSON-XS

GPERF_LIB_DEPENDS=	libprofiler.so:devel/google-perftools
GPERF_CMAKE_ON=		-DENABLE_GPERF_TOOLS=ON

HYPERSCAN_LIB_DEPENDS=	libhs.so:devel/hyperscan
HYPERSCAN_CMAKE_ON=	-DENABLE_HYPERSCAN=ON

LUAJIT_USES=		luajit
LUAJIT_USES_OFF=	lua:51+
LUAJIT_CMAKE_OFF=	-DENABLE_LUAJIT=OFF

post-install:
	@${MKDIR} \
		${STAGEDIR}/var/log/rspamd \
		${STAGEDIR}/var/db/rspamd \
		${STAGEDIR}/var/run/rspamd
	${RM} ${STAGEDIR}/${ETCDIR}/rspamd.conf.sample
	# Linux specific
	${RM} ${STAGEDIR}/${ETCDIR}/rspamd.systemd.conf
	${RM} ${STAGEDIR}/${ETCDIR}/rspamd.sysvinit.conf
	${INSTALL_DATA} ${WRKDIR}/rspamd.newsyslog.conf.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${LN} -s ${ETCDIR}/rspamd.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
post-install-CGP-on:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/cgp_rspamd.pl ${STAGEDIR}${PREFIX}/bin/rspamd-cgp-helper

.include <bsd.port.mk>
