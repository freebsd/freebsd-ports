# $FreeBSD$

PORTNAME=	rspamd
PORTVERSION=	1.5.0.a3.20170120
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system dev version

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libevent.so:devel/libevent2 \
		libluajit-5.1.so:lang/luajit \
		libfann.so:math/fann
BUILD_DEPENDS=	ragel:devel/ragel

CONFLICTS_INSTALL=	rspamd

RSPAMD_VERSION=	1.5.0
USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov
GH_TAGNAME=	a037e79

OPTIONS_DEFINE=	GPERF REDIRECTOR HYPERSCAN GD
OPTIONS_DEFAULT=	GD
GPERF_DESC=		Google perf-tools profiling
REDIRECTOR_DESC=	Install HTTP redirector
HYPERSCAN_DESC=		Use hyperscan optimizations (amd64 only)
GD_DESC=		Enable libgd support for images fuzzy hashes

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

USES=		cmake:outsource gettext iconv pkgconfig perl5 \
		compiler:c11 sqlite ssl
USE_LDCONFIG=	yes
USE_PERL5=	build

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
 ONLY_FOR_ARCHS=	amd64
.endif

.if ${PORT_OPTIONS:MREDIRECTOR}
 USE_PERL5+=	run
 CMAKE_ARGS+=	-DENABLE_REDIRECTOR=ON
 PLIST_SUB+=	REDIRECTOR=""
 USE_RC_SUBR+=	rspamd_redirector
 RUN_DEPENDS+=	\
	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
	p5-IO-String>=0:devel/p5-IO-String \
	p5-XML-Parser>=0:textproc/p5-XML-Parser \
	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
	p5-POE-Component-Client-DNS>=0:dns/p5-POE-Component-Client-DNS \
	p5-POE-Component-Client-HTTP>=0:www/p5-POE-Component-Client-HTTP \
	p5-POE-Component-Server-HTTP>=0:www/p5-POE-Component-Server-HTTP \
	p5-Cache-Memcached-Fast>=0:databases/p5-Cache-Memcached-Fast \
	p5-Proc-PidUtil>=0:sysutils/p5-Proc-PidUtil \
	p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
	p5-SWF-File>=0:graphics/p5-SWF-File
.else
 PLIST_SUB+=	REDIRECTOR="@comment "
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

.include <bsd.port.mk>
