PORTNAME=	snort
PORTVERSION=	2.9.20
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://snort.org/downloads/snort/ \
		https://snort.org/downloads/archive/snort/

PATCH_DIST_STRIP=	-p1

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system
WWW=		https://www.snort.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	daq>=2.2.2_3:net/daq
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libdnet.so:net/libdnet \
		libpcap.so:net/libpcap
RUN_DEPENDS=	daq>=2.2.2_3:net/daq

USES=			bison cpe libtool pathfix shebangfix ssl
USE_RC_SUBR=		snort
USE_LDCONFIG=		yes

SUB_FILES=		pkg-message
SHEBANG_FILES=		tools/appid_detector_builder.sh
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

RULES_DIR=		${ETCDIR}/rules
PREPROC_RULE_DIR=	${ETCDIR}/preproc_rules
LOGS_DIR=		/var/log/snort

CONFLICTS_INSTALL=	snort3-3.*

OPTIONS_DEFINE=		IPV6 GRE HA NORMALIZER DOCS APPID \
			PERFPROFILE LRGPCAP SOURCEFIRE NONETHER \
			FILEINSPECT

OPTIONS_GROUP=		ADDONS DEV
OPTIONS_GROUP_ADDONS=	BARNYARD PULLEDPORK
OPTIONS_GROUP_DEV=	DBGSNORT COREDUMPS
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	GRE NORMALIZER BARNYARD \
			PERFPROFILE SOURCEFIRE PULLEDPORK

GRE_DESC=		GRE support
IPV6_DESC=		IPv6 in snort.conf
LRGPCAP_DESC=		Pcaps larger than 2GB
NONETHER_DESC=		Non-Ethernet Decoders
NORMALIZER_DESC=	Normalizer
PERFPROFILE_DESC=	Performance profiling
SOURCEFIRE_DESC=	Sourcefire recommended build options
APPID_DESC=		Build with application id support (EXPERIMENTAL)
HA_DESC=		Enable high-availability state sharing (EXPERIMENTAL)
FILEINSPECT_DESC=	Build with extended file inspection features (EXPERIMENTAL)
ADDONS_DESC=		Depend on 3rd party addons
BARNYARD_DESC=		Depend on barnyard2 (supports also snortsam)
PULLEDPORK_DESC=	Depend on pulledpork
DEV_DESC=		Developer options
DBGSNORT_DESC=		Enable debugging symbols
COREDUMPS_DESC=		Enable core dumps

COREDUMPS_CONFIGURE_ENABLE=	corefiles
DBGSNORT_CONFIGURE_ENABLE=	debug
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

BARNYARD_RUN_DEPENDS=	barnyard2:security/barnyard2
PULLEDPORK_RUN_DEPENDS=	pulledpork.pl:security/pulledpork
APPID_USES=		luajit
APPID_CONFIGURE_ENV+=	luajit_CFLAGS="-I${LUAJIT_INCDIR}" \
			luajit_LIBS="-L${LOCALBASE}/lib -lluajit-5.1"

# Disable SIMD on 32-bit arm. Snort has numerous arbitrarily misaligned memory
# accesses and some of them cause faults. The kludge below combined with
# patch-configure seems to work around it well enough.
#
# Note the change is more aggressive than it possibly needs to be reduce surprises.
CFLAGS_armv6=	-mfpu=vfpv3
CFLAGS_armv7=	-mfpu=vfpv3

CONFIG_FILES=	classification.config gen-msg.map reference.config \
		snort.conf threshold.conf unicode.map file_magic.conf

DOCS=		RELEASE.NOTES doc/AUTHORS doc/BUGS doc/CREDITS \
		doc/README* doc/USAGE doc/*.pdf
PREPROC_RULES=	decoder.rules preprocessor.rules sensitive-data.rules

CFLAGS+=	-fstack-protector
CONFIGURE_ARGS+=--enable-reload \
		--enable-mpls --enable-targetbased \
		--enable-reload-error-restart

post-patch:
	@${REINPLACE_CMD} "s,/etc/snort.conf,${ETCDIR}/snort.conf," \
		${WRKSRC}/src/snort.c ${WRKSRC}/snort.8

	@${REINPLACE_CMD} -e 's|^dynamicdetection|#dynamicdetection|' \
		-e '/ipvar HOME_NET/s/any/[YOU_NEED_TO_SET_HOME_NET_IN_snort.conf]/' \
		-e '/^# include .PREPROC_RULE/s/# include/include/' \
		${WRKSRC}/etc/snort.conf

post-patch-IPV6-off:
# IPv6 is no longer a ./configure option!
	@${REINPLACE_CMD} -e '/normalize_ip6/s/^preprocessor/#preprocessor/' \
		-e '/normalize_icmp6/s/^preprocessor/#preprocessor/' \
		${WRKSRC}/etc/snort.conf

post-build:
	@${FIND} ${WRKSRC}/src -name '*.0' -type f -exec ${STRIP_CMD} {} \;

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${RULES_DIR} ${STAGEDIR}${LOGS_DIR} \
		${STAGEDIR}${PREPROC_RULE_DIR}

.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${STAGEDIR}${ETCDIR}/${f}-sample
.endfor

.for f in ${PREPROC_RULES}
	${INSTALL_DATA} ${WRKSRC}/preproc_rules/${f} ${STAGEDIR}${PREPROC_RULE_DIR}/${f}-sample
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREPROC_RULE_DIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
