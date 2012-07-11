# New ports collection makefile for:	suricata
# Date created:		Sun Aug 29 16:39:08 BRT 2010
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	suricata
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.openinfosecfoundation.org/download/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Open Source next generation IDS/IPS engine by OISF

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		yaml:${PORTSDIR}/textproc/libyaml \
		htp:${PORTSDIR}/devel/libhtp

BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
		pkg-config:${PORTSDIR}/devel/pkg-config

USE_AUTOTOOLS=	automake autoconf libtool

USE_RC_SUBR=	suricata

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

OPTIONS_DEFINE=	IPFW PRELUDE PORTS_PCAP DAG
OPTIONS_DEFAULT=IPFW

IPFW_DESC=	Enable ipfw/ipdivert for IPS usage
PRELUDE_DESC=	Enable Prelude NIDS integration
PORTS_PCAP_DESC=Use libpcap from ports
DAG_DESC=	Enable Endace DAG Support

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-non-bundled-htp --enable-gccprotect \
		--with-libpcre-includes=${LOCALBASE}/include \
		--with-libpcre-libraries=${LOCALBASE}/lib \
		--with-libyaml-includes=${LOCALBASE}/include \
		--with-libyaml-libraries=${LOCALBASE}/lib \
		--with-libnet-includes=${LOCALBASE}/include/libnet11 \
		--with-libnet-libraries=${LOCALBASE}/lib/libnet11

CONFIG_DIR?=	${PREFIX}/etc/suricata
CONFIG_FILES=	suricata.yaml classification.config reference.config
RULES_DIR=	${PREFIX}/etc/suricata/rules
LOGS_DIR=	/var/log/suricata

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

AUTOTOOLSFILES=	aclocal.m4 libhtp/aclocal.m4

post-patch:
	@${REINPLACE_CMD} -Ee 's|^(install-data-am: )install-pkgconfigDATA|\1|' ${WRKSRC}/libhtp/Makefile.in
.for f in ${AUTOTOOLSFILES}
	@${REINPLACE_CMD} -e 's|1.11.3|%%AUTOMAKE_APIVER%%|g' ${WRKSRC}/${f}
.endfor

pre-install:
	@${REINPLACE_CMD} -e 's|/etc/suricata|${PREFIX}/etc/suricata|g' ${WRKSRC}/suricata.yaml

post-install:
	[ -d ${CONFIG_DIR} ] || ${MKDIR} ${CONFIG_DIR}
	[ -d ${RULES_DIR} ] || ${MKDIR} ${RULES_DIR}
	[ -d ${LOGS_DIR} ] || ${MKDIR} ${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${CONFIG_DIR}/${f}-sample
	@if [ ! -f ${CONFIG_DIR}/${f} ]; then \
		${CP} -p ${CONFIG_DIR}/${f}-sample ${CONFIG_DIR}/${f} ; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
