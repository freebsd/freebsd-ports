# New ports collection makefile for:	suricata
# Date created:		Sun Aug 29 16:39:08 BRT 2010
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	suricata
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://openinfosecfoundation.org/download/ \
		http://www6.freebsdbrasil.com.br/~eksffa/l/dev/suricata/

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Open Source next generation IDS/IPS engine by OISF

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		yaml:${PORTSDIR}/textproc/libyaml \
		pcap.1:${PORTSDIR}/net/libpcap

BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
		pkg-config:${PORTSDIR}/devel/pkg-config

USE_AUTOTOOLS=	automake110 autoconf:268 libtool:22

USE_RC_SUBR=	suricata

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

OPTIONS=	IPFW "Enable IPFW/IPDIVERT for IPS usage" on \
		PRELUDE "Enable Prelude NIDS integration" off

SUB_FILES=	pkg-message
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIG_DIR?=	${PREFIX}/etc/suricata
CONFIG_FILES=	suricata.yaml classification.config
RULES_DIR=	${PREFIX}/etc/suricata/rules
LOGS_DIR=	/var/log/suricata

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif
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
