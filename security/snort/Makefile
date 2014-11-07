# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snort
PORTVERSION=	2.9.7.0
CATEGORIES=	security
MASTER_SITES=	SF/snort/snort \
		http://mirrors.rit.edu/zi/

PATCH_DIST_STRIP=	-p1

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libnet.so:${PORTSDIR}/net/libnet
BUILD_DEPENDS=	daq>=2.0.0:${PORTSDIR}/net/daq
RUN_DEPENDS=	daq>=2.0.0:${PORTSDIR}/net/daq

OPTIONS_DEFINE=		IPV6 GRE HA NORMALIZER DOCS APPID \
			PERFPROFILE LRGPCAP SOURCEFIRE NONETHER

OPTIONS_GROUP=		ADDONS DEV
OPTIONS_GROUP_ADDONS=	BARNYARD PULLEDPORK
OPTIONS_GROUP_DEV=	DBGSNORT
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	IPV6 GRE NORMALIZER BARNYARD \
			PERFPROFILE SOURCEFIRE PULLEDPORK

GRE_DESC=		GRE support
IPV6_DESC=		IPv6 in snort.conf
LRGPCAP_DESC=		Pcaps larger than 2GB
NONETHER_DESC=		Non-Ethernet Decoders
NORMALIZER_DESC=	Normalizer
PERFPROFILE_DESC=	Performance profiling
SOURCEFIRE_DESC=	Sourcefire recommended build options
TARGETBASED_DESC=	Targetbased support
APPID_DESC=		Build with application id support (EXPERIMENTAL)
HA_DESC=		Enable high-availability state sharing (EXPERIMENTAL)
FILEINSPECT_DESC=	Build with extended file inspection features (EXPERIMENTAL)
ADDONS_DESC=		Depend on 3rd party addons
BARNYARD_DESC=		Depend on barnyard2 (supports also snortsam)
PULLEDPORK_DESC=	Depend on pulledpork
DEV_DESC=		Developper options
DBGSNORT_DESC=		Enable debugging symbols+core dumps

DBGSNORT_CONFIGURE_ENABLE=	corefiles debug
DBGSNORT_MAKE_ENV=		DONTSTRIP="yes"
GRE_CONFIGURE_ENABLE=		gre
LRGPCAP_CONFIGURE_ENABLE=	large-pcap
NONETHER_CONFIGURE_ENABLE=	non-ether-decoders
NORMALIZER_CONFIGURE_ENABLE=	normalizer
PERFPROFILE_CONFIGURE_ENABLE=	perfprofiling ppm
SOURCEFIRE_CONFIGURE_ENABLE=	sourcefire
APPID_CONFIGURE_ENABLE=		open-appid
HA_CONFIGURE_ENABLE=		ha
FILEINSPECT_CONFIGURE_ENABLE=	file-inspect

BARNYARD_RUN_DEPENDS=	barnyard2:${PORTSDIR}/security/barnyard2
PULLEDPORK_RUN_DEPENDS=	pulledpork.pl:${PORTSDIR}/security/pulledpork
APPID_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
APPID_CONFIGURE_ENV+=	luajit_CFLAGS="-I${LOCALBASE}/include/luajit-2.0" \
			luajit_LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.options.mk>

USE_RC_SUBR=	snort
SUB_FILES=	pkg-message

USES=		pathfix libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

RULES_DIR=		${ETCDIR}/rules
PREPROC_RULE_DIR=	${ETCDIR}/preproc_rules
LOGS_DIR=		/var/log/snort

CONFIG_FILES=	classification.config gen-msg.map reference.config \
		snort.conf threshold.conf unicode.map

DOCS=		RELEASE.NOTES doc/AUTHORS doc/BUGS doc/CREDITS \
		doc/README* doc/USAGE doc/*.pdf
PREPROC_RULES=	decoder.rules preprocessor.rules sensitive-data.rules

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
CONFIGURE_ARGS+=--enable-reload \
		--enable-mpls --enable-targetbased \
		--enable-reload-error-restart \
		--with-dnet-includes=${LIBNET_INCDIR} \
		--with-dnet-libraries=${LIBNET_LIBDIR}

post-patch:
	@${FIND} ${WRKSRC} \( -name 'Makefile.in' -o -name snort.conf \) -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g'

	@${REINPLACE_CMD} "s,/etc/snort.conf,${ETCDIR}/snort.conf," \
		${WRKSRC}/src/snort.c ${WRKSRC}/snort.8

	@${REINPLACE_CMD} -e 's|^dynamicdetection|#dynamicdetection|' \
		-e '/ipvar HOME_NET/s/any/[YOU_NEED_TO_SET_HOME_NET_IN_snort.conf]/' \
		-e '/^# include .PREPROC_RULE/s/# include/include/' \
		${WRKSRC}/etc/snort.conf

	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|g' ${WRKSRC}/configure

# IPv6 is no longer a ./configure option!
.if ! ${PORT_OPTIONS:MIPV6}
	@${REINPLACE_CMD} -e '/normalize_ip6/s/^preprocessor/#preprocessor/' \
		-e '/normalize_icmp6/s/^preprocessor/#preprocessor/' \
		${WRKSRC}/etc/snort.conf
.endif

post-build:
	@${FIND} ${WRKSRC}/src -name '*.0' -type f -exec ${STRIP_CMD} {} \;

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${RULES_DIR} ${STAGEDIR}${LOGS_DIR} \
		${STAGEDIR}${PREPROC_RULE_DIR} ${STAGEDIR}${DOCSDIR}

.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${STAGEDIR}${ETCDIR}/${f}-sample
.endfor

.for f in ${PREPROC_RULES}
	${INSTALL_DATA} ${WRKSRC}/preproc_rules/${f} ${STAGEDIR}${PREPROC_RULE_DIR}/${f}-sample
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
