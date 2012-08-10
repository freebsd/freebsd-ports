# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.9.3.1
CATEGORIES=	security
MASTER_SITES=	SF/snort/snort \
		http://mirrors.rit.edu/zi/

PATCH_DIST_STRIP=	-p1

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	daq>=1.1.1:${PORTSDIR}/net/daq \
		${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet
RUN_DEPENDS=	daq>=1.1.1:${PORTSDIR}/net/daq \
		${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet

OPTIONS_DEFINE=	IPV6 MPLS GRE TARGETBASED ZLIB NORMALIZER REACT \
		PERFPROFILE FLEXRESP3 LRGPCAP SNORTSAM SOURCEFIRE \
		DBGSNORT
OPTIONS_DEFAULT=IPV6 MPLS GRE ZLIB NORMALIZER REACT PERFPROFILE \
		FLEXRESP3 SOURCEFIRE TARGETBASED

GRE_DESC=		Enable GRE support
TARGETBASED_DESC=	Enable targetbased support
ZLIB_DESC=		Enable GZIP support
NORMALIZER_DESC=	Enable normalizer
REACT_DESC=		Enable react
PERFPROFILE_DESC=	Enable performance profiling
FLEXRESP3_DESC=		Enable flexible response on events (v3)
LRGPCAP_DESC=		Enable pcaps larger than 2GB
SNORTSAM_DESC=		Enable unofficial Snortsam patch
SOURCEFIRE_DESC=	Enable Sourcefire-specific build options
DBGSNORT_DESC=		Enable debugging symbols+core dumps

.include <bsd.port.options.mk>

USE_RC_SUBR=	snort
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
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

CFLAGS+=	-fstack-protector
CONFIGURE_ARGS=	--enable-dynamicplugin --enable-build-dynamic-examples \
		--enable-reload --enable-reload-error-restart \
		--with-dnet-includes=${LIBNET_INCDIR} \
		--with-dnet-libraries=${LIBNET_LIBDIR}

PLIST_SUB+=	DYNAMIC=""

.if empty(PORT_OPTIONS:MFLEXRESP3)
CONFIGURE_ARGS+=--disable-flexresp3 --disable-active-response
.endif

.if ${PORT_OPTIONS:MLRGPCAP}
CONFIGURE_ARGS+=--enable-large-pcap
.endif

.if ${PORT_OPTIONS:MDBGSNORT}
CONFIGURE_ARGS+=--enable-corefiles --enable-debug
MAKE_ENV+=	DONTSTRIP="yes"
.else
CONFIGURE_ARGS+=--disable-corefiles
.endif

.if ${PORT_OPTIONS:MSOURCEFIRE}
CONFIGURE_ARGS+=--enable-sourcefire
.endif

.if empty(PORT_OPTIONS:MPERFPROFILE)
CONFIGURE_ARGS+=--disable-perfprofiling --disable-ppm
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if empty(PORT_OPTIONS:MGRE)
CONFIGURE_ARGS+=--disable-gre
.endif

.if empty(PORT_OPTIONS:MMPLS)
CONFIGURE_ARGS+=--disable-mpls
.endif

.if empty(PORT_OPTIONS:MTARGETBASED)
CONFIGURE_ARGS+=--disable-targetbased
.endif

.if empty(PORT_OPTIONS:MZLIB)
CONFIGURE_ARGS+=--disable-zlib
.endif

.if ${PORT_OPTIONS:MNORMALIZER}
CONFIGURE_ARGS+=--enable-normalizer
.endif

.if ${PORT_OPTIONS:MREACT}
CONFIGURE_ARGS+=--enable-react
.endif

.if ${PORT_OPTIONS:MSNORTSAM}
BROKEN=		current snortsam patch fails to apply
USE_AUTOTOOLS+=	automake
USE_GNOME=	pkgconfig
PATCH_SITES+=	http://www.snortsam.net/files/snort-plugin/:snortsam
PATCHFILES+=	snortsam-2.9.2.2.diff.gz:snortsam
.endif

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g'
	@${REINPLACE_CMD} "s,/etc/snort.conf,${CONFIG_DIR}/snort.conf," ${WRKSRC}/src/snort.c ${WRKSRC}/snort.8
	@${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g' ${WRKSRC}/etc/snort.conf
	@${REINPLACE_CMD} -e 's|^dynamicdetection|#dynamicdetection|' ${WRKSRC}/etc/snort.conf
	@${REINPLACE_CMD} -e '/var HOME_NET/s/any/[YOU_NEED_TO_SET_HOME_NET_IN_snort.conf]/' ${WRKSRC}/etc/snort.conf
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in \
		${WRKSRC}/src/dynamic-preprocessors/libs/Makefile.in ${WRKSRC}/src/dynamic-output/libs/Makefile.in
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|g' ${WRKSRC}/configure
.if empty(PORT_OPTIONS:MIPV6)
	@${REINPLACE_CMD} -e 's|^ipvar |var |' ${WRKSRC}/etc/snort.conf
	@${REINPLACE_CMD} -e '/normalize_ip6/s/^preprocessor/#preprocessor/'  ${WRKSRC}/etc/snort.conf
	@${REINPLACE_CMD} -e '/normalize_icmp6/s/^preprocessor/#preprocessor/'  ${WRKSRC}/etc/snort.conf
.endif
	@${REINPLACE_CMD} -e '/^# include .PREPROC_RULE/s/# include/include/' ${WRKSRC}/etc/snort.conf
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} '/SUBDIRS = /s/doc//' ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/README.u2boat/d' \
		-e '/test.*docdir.*MKDIR.*DEST/d' ${WRKSRC}/tools/u2boat/Makefile.*
.endif

pre-configure:
.if ${PORT_OPTIONS:MSNORTSAM}
	@${FIND} ${WRKSRC} -name 'Makefile.am' | ${XARGS} ${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g'
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.am \
		${WRKSRC}/src/dynamic-preprocessors/libs/Makefile.am \
		${WRKSRC}/src/dynamic-output/libs/Makefile.am
	@${ECHO_MSG} "===>   Rebuilding required files for snortsam patches..."
	@cd ${WRKSRC} && ${SH} ${WRKSRC}/autojunk.sh
	@${ECHO_MSG} "===>   Done.  Configuring..."
.endif

post-install:
	@${LIBTOOL} --finish ${LOCALBASE}/lib/snort/dynamicpreprocessor
	[ -d ${CONFIG_DIR} ] || ${MKDIR} ${CONFIG_DIR}
	[ -d ${RULES_DIR} ] || ${MKDIR} ${RULES_DIR}
	[ -d ${LOGS_DIR} ] || ${MKDIR} ${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${CONFIG_DIR}/${f}-sample
	@if [ ! -f ${CONFIG_DIR}/${f} ]; then \
		${CP} -p ${CONFIG_DIR}/${f}-sample ${CONFIG_DIR}/${f} ; \
	fi
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${PREPROC_RULE_DIR}
.for f in ${PREPROC_RULES}
	${INSTALL_DATA} ${WRKSRC}/preproc_rules/${f} ${PREPROC_RULE_DIR}/${f}-sample
	@if [ ! -f ${PREPROC_RULE_DIR}/${f} ]; then \
		${CP} -p ${PREPROC_RULE_DIR}/${f}-sample ${PREPROC_RULE_DIR}/${f} ; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
