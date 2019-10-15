# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcp
ISCVERSION=	4.4.1
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/:S/a/.a/:S/rc/.rc/}
PORTREVISION=	${DHCP_PORTREVISION}
CATEGORIES=	net
MASTER_SITES=	ISC/${PORTNAME}/${PORTVERSION:S/P/-P/g} \
		ZI
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	44-${SUBSYS}
DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT?=	ISC Dynamic Host Configuration Protocol server

LICENSE=	MPL20

USES=		gmake

PORTREVISION_SERVER=	4
PORTREVISION_CLIENT=	1
PORTREVISION_RELAY=	0

SUBSYS?=	server

OPTIONS_DEFINE=	IPV6
OPTIONS_SUB=	yes

.if ${SUBSYS} == server
OPTIONS_DEFINE+=	PARANOIA LDAP LDAP_SSL BIND_SYMBOLS DHCP4O6 \
			BINLEASES
OPTIONS_DEFAULT+=	PARANOIA LDAP_SSL
DHCP4O6_DESC=		Enable DHCPv4-over-DHCPv6 (TSV)
PARANOIA_DESC=		Enable support for chroot
LDAP_SSL_DESC=		Support LDAP over SSL/TLS
BIND_SYMBOLS_DESC=	Enable BIND internal symbol table
BINLEASES_DESC=		Enable support for binary insertion of leases
.endif

# PORTREVISION and CONFLICTS handling
.if ${SUBSYS} == client
CONFLICTS=	isc-dhcp3?-client-[0-9]* isc-dhcp4[123]-client-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_CLIENT}
.elif ${SUBSYS} == relay
CONFLICTS=	isc-dhcp3?-relay-[0-9]* isc-dhcp4[123]-relay-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_RELAY}
.else
CONFLICTS=	isc-dhcp3?-server-[0-9]* isc-dhcp4[123]-server-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_SERVER}
.endif
MAKE_JOBS_UNSAFE=	yes

.if ${SUBSYS} == server
USERS=		dhcpd
GROUPS=		dhcpd
.endif

MAN_COMPRESSED=	no
GNU_CONFIGURE=	yes
CPPFLAGS+=	-D_PATH_DHCLIENT_SCRIPT='\"${PREFIX}/sbin/dhclient-script\"' -D_PATH_DHCLIENT_CONF='\"${PREFIX}/etc/dhclient.conf\"' -D_PATH_DHCPD_CONF='\"${PREFIX}/etc/dhcpd.conf\"'
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}

.if ${SUBSYS} == server
CONFIGURE_ARGS+=--localstatedir=/var
CFLAGS+=	-fPIC
.endif

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

.if ${SUBSYS} == server
USE_RC_SUBR=	isc-dhcpd
.elif ${SUBSYS} == relay
USE_RC_SUBR=	isc-dhcrelay
.endif

SCHEMA_DIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
DATADIR=	/var/db

MSG_FILE=	${.CURDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

REINPLACE_SUB=	PREFIX="${PREFIX}"
PKGMESSAGE_SUB=	PREFIX="${PREFIX}" MAN1PREFIX="${MAN1PREFIX}" \
		DOCSDIR="${DOCSDIR}"

BINLEASES_CONFIGURE_ENABLE=	binary-leases
PARANOIA_CONFIGURE_ENABLE=	paranoia early-chroot
LDAP_CONFIGURE_WITH=		ldap ldapcrypto
LDAP_USE=			OPENLDAP
LDAP_USES=			shebangfix
LDAP_SSL_USES=			ssl
LDAP_SSL_VARS=			LIBS+=-lssl
IPV6_CONFIGURE_ENABLE=		dhcpv6
DHCP4O6_CONFIGURE_ENABLE=	dhcpv4o6
BIND_SYMBOLS_USES=		perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
LDAP_SCRIPT=	${WRKSRC}/contrib/ldap/dhcpd-conf-to-ldap
LDAP_SCHEMA=	${WRKSRC}/contrib/ldap/dhcp.schema
LDAP_README=	${WRKSRC}/contrib/ldap/README.ldap
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIBS+=		-L${LOCALBASE}/lib
PORTDOCS+=	README.ldap
PLIST_SUB+=	SCHEMA_DIR="${SCHEMA_DIR:S,^${PREFIX}/,,}" LDAP=""
SHEBANG_FILES=	contrib/ldap/dhcpd-conf-to-ldap
.endif

.if empty(PORT_OPTIONS:MBIND_SYMBOLS)
EXTRA_PATCHES+=${PATCHDIR}/extra-patch-bind_Makefile.in
.endif

.if ${PORT_OPTIONS:MPARANOIA}
SUB_LIST+=	PARANOIAOPT="yes"
.else
SUB_LIST+=	PARANOIAOPT="no"
.endif

post-patch:
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|/usr/local||g' \
		${WRKSRC}/doc/examples/dhcpd-dhcpv6.conf
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/client/dhclient.conf.example

do-install:
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/${SUBSYS} install
.if ${SUBSYS} == server
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/dhcpctl install
#${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/dst install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/omapip install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/includes install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/common install
	${INSTALL_DATA} ${WRKSRC}/dhcpctl/dhcpctl.h ${STAGEDIR}${PREFIX}/include
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpd.conf.example ${STAGEDIR}${PREFIX}/etc/dhcpd.conf.sample
.if ${PORT_OPTIONS:MIPV6}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/dhcpd-dhcpv6.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpd6.conf.sample
.endif
.if ${PORT_OPTIONS:MLDAP}
	@${MKDIR} ${STAGEDIR}${SCHEMA_DIR}
	${INSTALL_DATA} ${LDAP_SCHEMA} ${STAGEDIR}${SCHEMA_DIR}
	${INSTALL_SCRIPT} ${LDAP_SCRIPT} ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLDAP}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${LDAP_README} ${STAGEDIR}${DOCSDIR}
.endif
.endif
.if ${SUBSYS} == client
	${INSTALL_SCRIPT} ${WRKSRC}/client/scripts/freebsd ${STAGEDIR}${PREFIX}/sbin/dhclient-script
.elif ${SUBSYS} == server
.if ${PORT_OPTIONS:MIPV6}
	@${LN} -sf isc-dhcpd ${STAGEDIR}${PREFIX}/etc/rc.d/isc-dhcpd6
.endif
.elif ${SUBSYS} == relay
.if ${PORT_OPTIONS:MIPV6}
	@${LN} -sf isc-dhcrelay ${STAGEDIR}${PREFIX}/etc/rc.d/isc-dhcrelay6
.endif
.endif
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}

.include <bsd.port.mk>
