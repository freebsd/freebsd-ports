# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.9.0.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/snort/snort

PATCH_DIST_STRIP=	-p1

MAINTAINER=	wfreeman@sourcefire.com
COMMENT=	Lightweight network intrusion detection system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	daq>=0.5_1:${PORTSDIR}/net/daq \
		${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet
RUN_DEPENDS=	daq>=0.5_1:${PORTSDIR}/net/daq \
		${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet

OPTIONS=	IPV6 "Enable IPv6 support" off \
		MPLS "Enable MPLS support" on \
		GRE "Enable GRE support" on \
		TARGETBASED "Enable Targetbased support" off \
		DECODERPRE "Enable Decoded-Preprocessor-Rules" on \
		ZLIB "Enable GZIP support" on \
		NORMALIZER "Enable Normalizer" on \
		REACT "Enable React" on \
		PERFPROFILE "Enable Performance Profiling" on \
		FLEXRESP3 "Flexible response to events (version 3)" on \
		MYSQL "Enable MySQL support" off \
		ODBC "Enable ODBC support" off \
		POSTGRESQL "Enable PostgreSQL support" off \
		PRELUDE "Enable Prelude NIDS integration" off \
		SNORTSAM "Unofficial Snortsam Patch" off

.include <bsd.port.options.mk>

USE_RC_SUBR=	snort.sh
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_JOBS_UNSAFE=	yes

CONFIG_DIR?=	${PREFIX}/etc/snort
CONFIG_FILES=	classification.config gen-msg.map reference.config \
		snort.conf threshold.conf unicode.map
RULES_DIR=	${PREFIX}/etc/snort/rules
LOGS_DIR=	/var/log/snort

MAN8=		snort.8
DOCS=		RELEASE.NOTES doc/AUTHORS doc/BUGS doc/CREDITS \
		doc/README* doc/USAGE doc/*.pdf
PREPROC_RULE_DIR=	${RULES_DIR}/../preproc_rules
PREPROC_RULES=		decoder.rules preprocessor.rules sensitive-data.rules

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet11-config
.if exists(${LIBNET_CONFIG})
LIBNET_CFLAGS!=	${LIBNET_CONFIG} --cflags
LIBNET_LIBS!=	${LIBNET_CONFIG} --libs
.else
LIBNET_CFLAGS=	-I${LOCALBASE}/include/libnet11
LIBNET_LIBS=	-L${LOCALBASE}/lib/libnet11 -lnet
.endif
LIBNET_INCDIR=	${LIBNET_CFLAGS:M-I*:S/-I//}
LIBNET_LIBDIR=	${LIBNET_LIBS:M-L*:S/-L//}

CONFIGURE_ARGS=	--enable-dynamicplugin --enable-build-dynamic-examples \
		--enable-reload --enable-reload-restart \
		--disable-corefiles \
		--with-dnet-includes=${LIBNET_INCDIR} \
		--with-dnet-libraries=${LIBNET_LIBDIR}

PLIST_SUB+=	DYNAMIC=""

.if defined(WITH_FLEXRESP3)
CONFIGURE_ARGS+=	--enable-flexresp3 \
			--enable-active-response
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--with-odbc=no
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=		-lssl -lcrypto
.endif
.else
CONFIGURE_ARGS+=	--with-postgresql=no
.endif

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.20:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
PLIST_SUB+=		PRELUDE=""
.else
CONFIGURE_ARGS+=	--disable-prelude
PLIST_SUB+=		PRELUDE="@comment "
.endif

.if defined(WITH_PERFPROFILE)
CONFIGURE_ARGS+=	--enable-perfprofiling --enable-ppm
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_GRE)
CONFIGURE_ARGS+=	--enable-gre
.endif

.if defined(WITH_MPLS)
CONFIGURE_ARGS+=	--enable-mpls
.endif

.if defined(WITH_TARGETBASED)
CONFIGURE_ARGS+=	--enable-targetbased
.endif

.if defined(WITH_DECODERPRE)
CONFIGURE_ARGS+=	--enable-decoder-preprocessor-rules
.endif

.if defined(WITH_ZLIB)
CONFIGURE_ARGS+=	--enable-zlib
.endif

.if defined(WITH_NORMALIZER)
CONFIGURE_ARGS+=	--enable-normalizer
.endif

.if defined(WITH_REACT)
CONFIGURE_ARGS+=	--enable-react
.endif

.if defined(WITH_SNORTSAM)
USE_AUTOTOOLS+=	automake
PATCH_SITES+=	http://www.snortsam.net/files/snort-plugin/:snortsam
PATCHFILES+=	snortsam-2.9.0.3.diff.gz:snortsam
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} '/SUBDIRS = /s/doc//' ${WRKSRC}/Makefile.in
.endif

pre-configure:
	${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g'
	${REINPLACE_CMD} "s,/etc/snort.conf,${CONFIG_DIR}/snort.conf," ${WRKSRC}/src/snort.c ${WRKSRC}/snort.8
	${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g' ${WRKSRC}/etc/snort.conf
	${REINPLACE_CMD} -e 's|^dynamicdetection|#dynamicdetection|' ${WRKSRC}/etc/snort.conf
	${REINPLACE_CMD} -e '/var HOME_NET/s/any/[YOU_NEED_TO_SET_HOME_NET_IN_snort.conf]/' ${WRKSRC}/etc/snort.conf
	${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|g' ${WRKSRC}/configure
.if !defined(WITH_IPV6)
	${REINPLACE_CMD} -e 's|^ipvar |var |' ${WRKSRC}/etc/snort.conf
	${REINPLACE_CMD} -e '/normalize_ip6/s/^preprocessor/#preprocessor/'  ${WRKSRC}/etc/snort.conf
	${REINPLACE_CMD} -e '/normalize_icmp6/s/^preprocessor/#preprocessor/'  ${WRKSRC}/etc/snort.conf
.endif
.if defined(WITH_DECODERPRE)
	${REINPLACE_CMD} -e '/^# include .PREPROC_RULE/s/# include/include/' ${WRKSRC}/etc/snort.conf
.endif
.if defined(WITH_SNORTSAM)
	@cd ${WRKSRC} && ${SH} ${WRKSRC}/autojunk.sh
.endif

pre-install:
.if defined(WITH_POSTGRESQL)
	@${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| postgresql|' ${WRKDIR}/snort.sh
.endif
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/snort.sh
.endif

post-install:
.if defined(WITH_SNORTSAM)
	# mss: only doing this because snortsam patch/autojunk messes up paths
	# life is too short to figure out why.
	@${MKDIR} ${LOCALBASE}/lib/snort/dynamicrules
	@cd ${LOCALBASE}/lib && ${MKDIR} snort/dynamicrules &&  ${MKDIR} snort/dynamicengine &&  ${MKDIR} snort/dynamicpreprocessor
	@cd ${LOCALBASE}/lib && ${MV} snort_dynamicrules/* snort/dynamicrules
	@cd ${LOCALBASE}/lib && ${MV} snort_dynamicengine/* snort/dynamicengine
	@cd ${LOCALBASE}/lib && ${MV} snort_dynamicpreprocessor/* snort/dynamicpreprocessor
	@cd ${LOCALBASE}/lib && ${RMDIR} snort_dynamic*
	@${MKDIR} ${LOCALBASE}/libdata/pkgconfig/ && ${MV} ${LOCALBASE}/lib/pkgconfig/snort.pc ${LOCALBASE}/libdata/pkgconfig/snort.pc
	@${RMDIR} ${LOCALBASE}/lib/pkgconfig
.endif
	@${LIBTOOL} --finish ${LOCALBASE}/lib/snort/dynamicpreprocessor
	[ -d ${CONFIG_DIR} ] || ${MKDIR} ${CONFIG_DIR}
	[ -d ${EXAMPLESDIR} ] || ${MKDIR} ${EXAMPLESDIR}
	[ -d ${RULES_DIR} ] || ${MKDIR} ${RULES_DIR}
	[ -d ${LOGS_DIR} ] || ${MKDIR} ${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${CONFIG_DIR}/${f}-sample
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EXAMPLESDIR}/${f}-sample
	@if [ ! -f ${CONFIG_DIR}/${f} ]; then \
		${CP} -p ${CONFIG_DIR}/${f}-sample ${CONFIG_DIR}/${f} ; \
	fi
.endfor
	${INSTALL_DATA} ${WRKSRC}/schemas/create* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if defined(WITH_DECODERPRE)
	@${MKDIR} ${PREPROC_RULE_DIR}
.for f in ${PREPROC_RULES}
	${INSTALL_DATA} ${WRKSRC}/preproc_rules/${f} ${PREPROC_RULE_DIR}/${f}-sample
	@if [ ! -f ${PREPROC_RULE_DIR}/${f} ]; then \
		${CP} -p ${PREPROC_RULE_DIR}/${f}-sample ${PREPROC_RULE_DIR}/${f} ; \
	fi
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
