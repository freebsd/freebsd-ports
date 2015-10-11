# Created by: Mathieu Simon <freebsd@simweb.ch>
# $FreeBSD$

PORTNAME=	lldpd
PORTVERSION=	0.7.18
CATEGORIES=	net-mgmt
MASTER_SITES=	http://media.luffy.cx/files/${PORTNAME}/ \
		http://mirror.1labs.ch/${PORTNAME}/

MAINTAINER=	freebsd@simweb.ch
COMMENT=	LLDP (802.1ab)/CDP/EDP/SONMP/FDP daemon and SNMP subagent

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USES=		libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-hardening \
		--enable-privsep \
		--with-privsep-chroot=/var/empty \
		--with-lldpd-ctl-socket=/var/run/lldpd.socket \
		--with-lldpd-pid-file=/var/run/lldpd.pid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

USERS=	_lldpd
GROUPS=	_lldpd

OPTIONS_DEFINE=		BASH DOCS DTRACE JSON PROPRIETARY READLINE SNMP XML ZSH
OPTIONS_DEFAULT=	BASH JSON PROPRIETARY SNMP XML
OPTIONS_SUB=	yes

DTRACE_DESC=		DTrace support
JSON_DESC=		JSON output support
PROPRIETARY_DESC=	Support proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable the use of SNMP
XML_DESC=		XML output support

DTRACE_CONFIGURE_ENABLE=	dtrace
JSON_CONFIGURE_WITH=		json
READLINE_CONFIGURE_WITH=	readline
SNMP_CONFIGURE_WITH=		snmp
XML_CONFIGURE_WITH=		xml
PROPRIETARY_CONFIGURE_ENABLE=	cdp edp fdp sonmp

JSON_LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson
JSON_USES=		pkgconfig
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
XML_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

post-install:
	${INSTALL_DATA} ${FILESDIR}/README.bsd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
