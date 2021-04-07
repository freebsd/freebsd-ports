PORTNAME=	frr
PORTVERSION=	7.5.1
DISTVERSIONPREFIX=	frr-
PORTREVISION=	1
CATEGORIES=	net
.if defined(PYTHONTOOLS)
PKGNAMESUFFIX=	7-pythontools
.else
PKGNAMESUFFIX=	7
.endif

MAINTAINER=	olivier@FreeBSD.org

COMMENT?=	IP routing protocol suite including BGP, IS-IS, OSPF and RIP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.if defined(PYTHONTOOLS)
RUN_DEPENDS=	frr-reload:net/frr7

USES=	python:run,3.6+ shebangfix

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/frr|${ETCDIR}|g' \
		-e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/local/bin/tail|${TAIL}|g' \
		${WRKSRC}/tools/frr-reload.py

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/frr
	${INSTALL_SCRIPT} ${WRKSRC}/tools/frr-reload.py ${STAGEDIR}/${PREFIX}/lib/frr/
.else

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libyang.so:net/libyang

USES=		autoreconf bison compiler:c++11-lang gmake pkgconfig libtool \
		makeinfo python:build,3.6+ readline shebangfix

BINARY_ALIAS=	python=${PYTHON_VERSION}

CONFLICTS=	openbgpd openospfd zebra quagga

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	FRRouting

.if defined(PYTHONTOOLS)
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	tools/frr-reload.py
PLIST=			${.CURDIR}/pkg-plist
PKGMESSAGE=	""
.else
INFO=		frr

OPTIONS_DEFINE=		CONFIGROLLBACKS FPM DATACENTER LDPD PAM SHELLACCESS \
			VTYSH MANPAGES MULTIPATH TCMALLOC RPKI SNMP
OPTIONS_DEFAULT=	VTYSH RPKI FPM MANPAGES
OPTIONS_SUB=	yes

CONFIGROLLBACKS_DESC=	Enable configuration rollback support
FPM_DESC=		Enable Forwarding Plane Manager support
DATACENTER_DESC=	Use reduced BGP timers
LDPD_DESC=		Build ldpd
MULTIPATH_DESC=		Enable multipath function
PAM_DESC=		Use libpam for PAM support in vtysh
RPKI_DESC=		Add BGP RPKI (RFC 6810) support
SHELLACCESS_DESC=	Allow users to access shell/telnet/ssh
SNMP_DESC=		SNMP support
TCMALLOC_DESC=		Use tcmalloc
VTYSH_DESC=		Build integrated vty shell

USERS=	frr
GROUPS=	frr frrvty

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# PIM compile but didn't work on FreeBSD
CONFIGURE_ARGS=	--enable-user=frr \
		--enable-group=frr \
		--enable-vty-group=frrvty \
		--disable-doc-html \
		--sysconfdir=${ETCDIR} \
		--localstatedir=/var/run/frr \
		--disable-backtrace \
		--disable-nhrpd \
		--disable-pimd \
		--disable-vrrpd \
		--with-vtysh-pager=cat

MANPAGES_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_CONFIGURE_OFF=		--disable-doc
CONFIGROLLBACKS_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
CONFIGROLLBACKS_CONFIGURE_ENABLE=	config-rollbacks
DATACENTER_CONFIGURE_ENABLE=	datacenter
SHELLACCESS_CONFIGURE_ENABLE=	shell-access
FPM_CONFIGURE_ENABLE=		fpm
PAM_CONFIGURE_WITH=		libpam
LDPD_CONFIGURE_ENABLE=		ldpd
MULTIPATH_CONFIGURE_ON=		--enable-multipath=64
RPKI_CONFIGURE_ENABLE=		rpki
RPKI_LIB_DEPENDS=		librtr.so:net-mgmt/rtrlib \
				libssh.so:security/libssh
TCMALLOC_CONFIGURE_ENABLE=	tcmalloc
TCMALLOC_LIB_DEPENDS=		libtcmalloc.so:devel/google-perftools
SNMP_CONFIGURE_ENABLE=		snmp
SNMP_CFLAGS=			"-std=gnu99"
SNMP_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
SNMP_USES=			ssl
VTYSH_CONFIGURE_ENABLE=		vtysh

USE_RC_SUBR=	frr watchfrr

SHEBANG_FILES=	yang/embedmodel.py

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/frr|${ETCDIR}|g' \
		-e 's|/usr/lib/|${PREFIX}/lib/|g' \
		-e 's|frr-pythontools|frr7-pythontools|g' \
		${WRKSRC}/tools/frr-reload

post-install:
	${MKDIR} ${STAGEDIR}/var/run/frr
	${INSTALL_SCRIPT} ${WRKSRC}/tools/frr-reload ${STAGEDIR}${PREFIX}/sbin
.endif

.include <bsd.port.mk>
