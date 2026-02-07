PORTNAME=	frr
PORTVERSION=	9.1.3
DISTVERSIONPREFIX=	frr-
PORTREVISION=	1
CATEGORIES=	net
.if defined(PYTHONTOOLS)
PKGNAMESUFFIX=	9-pythontools
.else
PKGNAMESUFFIX=	9
.endif

MAINTAINER=	olivier@FreeBSD.org
COMMENT?=	IP routing protocol suite including BGP, IS-IS, OSPF, BABEL and RIP
WWW=		https://frrouting.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.if defined(PYTHONTOOLS)
RUN_DEPENDS=	frr-reload:net/frr9

USES=	python:run shebangfix

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/frr|${ETCDIR}|g' \
		-e 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/tools/frr-reload.py
	@${REINPLACE_CMD} -e 's|/etc/frr|${ETCDIR}|g' \
		${WRKSRC}/tools/generate_support_bundle.py

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/frr-reload.py ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/generate_support_bundle.py ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/tools/etc/frr/support_bundle_commands.conf ${STAGEDIR}${ETCDIR}/
.else

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libjson-c.so:devel/json-c \
		libpcre2-8.so:devel/pcre2 \
		libprotobuf-c.so:devel/protobuf-c \
		libyang.so.2:net/libyang2

USES=		autoreconf bison compiler:c++11-lang gmake libtool makeinfo \
		pkgconfig python:build readline shebangfix

BINARY_ALIAS=	python=${PYTHON_VERSION}

CONFLICTS=	frr8 frr10 openbgpd openospfd quagga zebra

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	FRRouting

.if defined(PYTHONTOOLS)
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	tools/frr-reload.py \
		tools/generate_support_bundle.py
PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	""
.else
INFO=		frr

OPTIONS_DEFINE=		BACKTRACE CONFIGROLLBACKS DATACENTER FPM LDPD MANPAGES \
			MULTIPATH PAM RPKI SHARPD SHELLACCESS SNMP TCMALLOC
OPTIONS_DEFAULT=	BACKTRACE FPM MANPAGES RPKI
OPTIONS_SUB=	yes

BACKTRACE_DESC=		Enable backtrace
CONFIGROLLBACKS_DESC=	Enable configuration rollback support
DATACENTER_DESC=	Use reduced BGP timers
FPM_DESC=		Enable Forwarding Plane Manager support
LDPD_DESC=		Build ldpd
MULTIPATH_DESC=		Allow 64 multipath routes (16 default)
PAM_DESC=		Use libpam for PAM support in vtysh
RPKI_DESC=		Add BGP RPKI (RFC 6810) support
SHARPD_DESC=		Build sharpd
SHELLACCESS_DESC=	Allow users to access shell/telnet/ssh
SNMP_DESC=		SNMP support
TCMALLOC_DESC=		Use tcmalloc

USERS=	frr
GROUPS=	frr frrvty

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# PIMD and PBRD compile but doesn't work on FreeBSD
CONFIGURE_ARGS=	--enable-user=frr \
		--enable-group=frr \
		--enable-vty-group=frrvty \
		--enable-vtysh \
		--disable-doc-html \
		--sysconfdir=${ETCDIR} \
		--localstatedir=/var/run/frr \
		--disable-nhrpd \
		--disable-pathd \
		--disable-ospfclient \
		--disable-pimd \
		--disable-pbrd \
		--with-vtysh-pager=cat

BACKTRACE_LIB_DEPENDS=		libunwind.so:devel/libunwind
BACKTRACE_CONFIGURE_ENABLE=	backtrace
CONFIGROLLBACKS_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
CONFIGROLLBACKS_CONFIGURE_ENABLE=	config-rollbacks
DATACENTER_CONFIGURE_ENABLE=	datacenter
FPM_CONFIGURE_ENABLE=		fpm
LDPD_CONFIGURE_ENABLE=		ldpd
MANPAGES_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_CONFIGURE_OFF=		--disable-doc
MULTIPATH_CONFIGURE_ON=		--enable-multipath=64
PAM_CONFIGURE_WITH=		libpam
RPKI_CONFIGURE_ENABLE=		rpki
RPKI_LIB_DEPENDS=		librtr.so:net-mgmt/rtrlib \
				libssh.so:security/libssh
SHARPD_CONFIGURE_ENABLE=	sharpd
SHELLACCESS_CONFIGURE_ENABLE=	shell-access
SNMP_CONFIGURE_ENABLE=		snmp
SNMP_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
SNMP_USES=			ssl
TCMALLOC_CONFIGURE_ENABLE=	tcmalloc
TCMALLOC_LIB_DEPENDS=		libtcmalloc.so:devel/google-perftools

USE_RC_SUBR=	frr

SHEBANG_FILES=	yang/embedmodel.py

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/frr|${ETCDIR}|g' \
		-e 's|/usr/lib/frr|${PREFIX}/sbin|g' \
		-e 's|frr-pythontools|frr9-pythontools|g' \
		${WRKSRC}/tools/frr-reload

post-install:
	${MKDIR} ${STAGEDIR}/var/run/frr
	${INSTALL_SCRIPT} ${WRKSRC}/tools/frr-reload ${STAGEDIR}${PREFIX}/sbin
.endif

.include <bsd.port.mk>
