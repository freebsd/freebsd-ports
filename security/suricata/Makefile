# New ports collection makefile for:	suricata
# Date created:		Sun Aug 29 16:39:08 BRT 2010
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	suricata
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.openinfosecfoundation.org/download/

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Open Source next generation IDS/IPS engine by OISF

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre \
		yaml:${PORTSDIR}/textproc/libyaml \
		pcap.1:${PORTSDIR}/net/libpcap \
		htp-0.2.1:${PORTSDIR}/devel/libhtp

BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
		pkg-config:${PORTSDIR}/devel/pkg-config

USE_AUTOTOOLS=	automake autoconf libtool

USE_RC_SUBR=	suricata

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

OPTIONS=	IPFW "Enable IPFW/IPDIVERT for IPS usage" on \
		PRELUDE "Enable Prelude NIDS integration" off \
		DAG "Enable Endace DAG Support" off

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

SUB_FILES=	pkg-message
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIG_DIR?=	${PREFIX}/etc/suricata
CONFIG_FILES=	suricata.yaml classification.config
RULES_DIR=	${PREFIX}/etc/suricata/rules
LOGS_DIR=	/var/log/suricata

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.20:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
PLIST_SUB+=		PRELUDE=""
.endif

.if defined(WITH_IPFW)
CONFIGURE_ARGS+=	--enable-ipfw
.endif

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--enable-dag
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|^(install-data-am: )install-pkgconfigDATA|\1|' ${WRKSRC}/libhtp/Makefile.in

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
