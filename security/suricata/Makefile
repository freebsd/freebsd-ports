# Created by: Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	suricata
PORTVERSION=	1.4.6
CATEGORIES=	security
MASTER_SITES=	http://www.openinfosecfoundation.org/download/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Open Source next generation IDS/IPS engine by OISF

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre		\
		libhtp.so:${PORTSDIR}/www/libhtp-suricata	\
		libnet.so:${PORTSDIR}/net/libnet                \
		libyaml.so:${PORTSDIR}/textproc/libyaml

OPTIONS_DEFINE=	IPFW PRELUDE PORTS_PCAP DAG TESTS
OPTIONS_DEFAULT=IPFW

IPFW_DESC=	Enable IPFW and IP Divert support for inline IDP
PRELUDE_DESC=	Enable Prelude support for NIDS alerts
PORTS_PCAP_DESC=Use libpcap from ports
DAG_DESC=	Enable Endace DAG capture support
TESTS_DESC=	Enable unit tests in suricata binary

USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-non-bundled-htp --enable-gccprotect		\
		--with-libpcre-includes=${LOCALBASE}/include		\
		--with-libpcre-libraries=${LOCALBASE}/lib		\
		--with-libyaml-includes=${LOCALBASE}/include		\
		--with-libyaml-libraries=${LOCALBASE}/lib		\
		--with-libnet-includes=${LOCALBASE}/include/libnet11	\
		--with-libnet-libraries=${LOCALBASE}/lib/libnet11	\
		--with-libhtp-includes=${LOCALBASE}/include/		\
		--with-libhtp-libraries=${LOCALBASE}/lib		\
		--localstatedir=/var/
CONFIGURE_ENV+=	ac_cv_path_HAVE_PYTHON_CONFIG=no

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config
CONFIG_DIR?=	${ETCDIR}
CONFIG_FILES=	suricata.yaml classification.config reference.config
RULES_DIR=	${CONFIG_DIR}/rules
LOGS_DIR?=	/var/log/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MPRELUDE}
LIB_DEPENDS+=		prelude:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude \
			--with-libprelude-prefix=${LOCALBASE}
PLIST_SUB+=		PRELUDE=""
.endif

.if ${PORT_OPTIONS:MIPFW}
CONFIGURE_ARGS+=	--enable-ipfw
.endif

.if ${PORT_OPTIONS:MPORTS_PCAP}
LIB_DEPENDS+=		pcap:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-libpcap-includes=${LOCALBASE}/include \
			--with-libpcap-libraries=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-libpcap-includes=/usr/include \
			--with-libpcap-libraries=/usr/lib
.endif

.if ${PORT_OPTIONS:MDAG}
CONFIGURE_ARGS+=	--enable-dag \
			--with-dag-includes=${LOCALBASE}/include \
			--with-dag-libraries=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MTESTS}
CONFIGURE_ARGS+=	--enable-unittests
.else
CONFIGURE_ARGS+=	--disable-unittests
.endif

pre-install:
	@${REINPLACE_CMD} -e 's|/etc/suricata|${CONFIG_DIR}|g' ${WRKSRC}/suricata.yaml

post-install:
	${MKDIR} ${STAGEDIR}${CONFIG_DIR}
	${MKDIR} ${STAGEDIR}${RULES_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${CONFIG_DIR}/${f}-sample
.endfor

TMPDIR?=	/tmp
TESTDIR=	${TMPDIR}/${PORTNAME}

regression-test: build
	${RM} -rf ${TESTDIR}
	${MKDIR} ${TESTDIR}
	cd ${WRKSRC}/src && ./suricata -u -l ${TESTDIR}
	${RM} -rf ${TESTDIR}

.include <bsd.port.post.mk>
