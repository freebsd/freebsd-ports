PORTNAME=	lldpd
DISTVERSION=	1.0.19
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/ \
		http://media.luffy.cx/files/${PORTNAME}/

MAINTAINER=	freebsd@simweb.ch
COMMENT=	Link-Layer Discovery Protocol (LLDP 802.1ab) daemon
WWW=		https://lldpd.github.io/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

FLAVORS=	default tiny
FLAVOR?=	${FLAVORS:[1]}
tiny_PKGNAMESUFFIX=	-tiny

USES=		cpe libtool pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/libevent \
			--no-same-owner --no-same-permissions

USE_RC_SUBR=	${PORTNAME}

USERS=		_lldpd
GROUPS= 	_lldpd

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-hardening \
		--enable-privsep \
		--with-privsep-chroot=/var/run/lldpd \
		--with-lldpd-ctl-socket=/var/run/lldpd.socket \
		--with-lldpd-pid-file=/var/run/lldpd.pid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if ${FLAVOR} == tiny
OPTIONS_UNSET=	${OPTIONS_DEFAULT}
SUB_LIST+=	BASH="@comment " \
		ZSH="@comment "
.endif

OPTIONS_DEFINE=		BASH DOCS LIBXML2 PIE PROPRIETARY READLINE SNMP ZSH
OPTIONS_DEFAULT=	BASH LIBXML2 PROPRIETARY SNMP ZSH
OPTIONS_SUB=		yes

PIE_DESC=		Build PIE (position independant executables)
PROPRIETARY_DESC=	Support proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable SNMP sub-agent (AgentX)

LIBXML2_USES=		gnome
LIBXML2_USE=		GNOME=libxml2
LIBXML2_CONFIGURE_WITH=	xml

PIE_CONFIGURE_ENABLE=	pie

PROPRIETARY_CONFIGURE_ENABLE=	cdp edp fdp sonmp

READLINE_CONFIGURE_WITH=	readline

SNMP_USES=		ssl
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp

post-install:
	${MKDIR} ${STAGEDIR}/var/run/lldpd

post-install-DOCS-on:
	${INSTALL_DATA} ${FILESDIR}/README.bsd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
