PORTNAME=	lldpd
PORTVERSION=	1.0.18
CATEGORIES=	net-mgmt
MASTER_SITES=	http://media.luffy.cx/files/${PORTNAME}/

MAINTAINER=	freebsd@simweb.ch
COMMENT=	Link-Layer Discovery Protocol (LLDP 802.1ab) daemon
WWW=		https://lldpd.github.io/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

FLAVORS=	default tiny
tiny_PKGNAMESUFFIX=	-tiny

USES=		cpe libtool pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-hardening \
		--enable-privsep \
		--with-privsep-chroot=/var/run/lldpd \
		--with-lldpd-ctl-socket=/var/run/lldpd.socket \
		--with-lldpd-pid-file=/var/run/lldpd.pid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

USERS=	_lldpd
GROUPS=	_lldpd

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:S/^/${PORTNAME}-/}

OPTIONS_DEFINE=		BASH DOCS DTRACE PIE PROPRIETARY READLINE SNMP XML ZSH
OPTIONS_DEFAULT=	BASH PROPRIETARY SNMP XML ZSH
# ld(1) fails to link probes: Relocations in generic ELF (EM: 0)
OPTIONS_EXCLUDE_aarch64=	DTRACE
# dt_modtext:opensolaris/lib/libdtrace/common/dt_link.c: arm not implemented
OPTIONS_EXCLUDE_armv6=		DTRACE
OPTIONS_EXCLUDE_armv7=		DTRACE
OPTIONS_SUB=	yes

.if ${FLAVOR:U} == tiny
OPTIONS_DEFAULT:=
.endif

DTRACE_DESC=		DTrace support (BROKEN)
PIE_DESC=		Build PIE (position independant executables)
PROPRIETARY_DESC=	Support proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable SNMP sub-agent (AgentX)
XML_DESC=		XML output support

DTRACE_CONFIGURE_ENABLE=	dtrace
PIE_CONFIGURE_ENABLE=		pie
PROPRIETARY_CONFIGURE_ENABLE=	cdp edp fdp sonmp
READLINE_CONFIGURE_WITH=	readline
SNMP_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
SNMP_USES=			ssl
SNMP_CONFIGURE_WITH=		snmp
XML_LIB_DEPENDS=		libxml2.so:textproc/libxml2
XML_CONFIGURE_WITH=		xml

post-install:
	${MKDIR} ${STAGEDIR}/var/run/lldpd

post-install-DOCS-on:
	${INSTALL_DATA} ${FILESDIR}/README.bsd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
