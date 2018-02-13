# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	dhcp
PORTVERSION=	4.3.6
PORTREVISION=	${DHCP_PORTREVISION}
CATEGORIES=	net
MASTER_SITES=	ISC/${PORTNAME}/${PORTVERSION:S/P/-P/g} \
		ZI
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	43-${SUBSYS}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/P/-P/g}

MAINTAINER=	zi@FreeBSD.org
COMMENT?=	ISC Dynamic Host Configuration Protocol server

LICENSE=	ISCL

USES=		gmake

PORTREVISION_SERVER=	3
PORTREVISION_CLIENT=	0
PORTREVISION_RELAY=	0

SUBSYS?=	server

OPTIONS_DEFINE=	IPV6

.if ${SUBSYS} == server
OPTIONS_DEFINE+=	PARANOIA LDAP LDAP_SSL BIND_SYMBOLS DHCP4O6
OPTIONS_DEFAULT+=	PARANOIA LDAP_SSL
DHCP4O6_DESC=		Enable DHCPv4-over-DHCPv6 (TSV)
PARANOIA_DESC=		Enable support for chroot
LDAP_SSL_DESC=		Support LDAP over SSL/TLS
BIND_SYMBOLS_DESC=	Enable BIND internal symbol table
.endif

# PORTREVISION and CONFLICTS handling
.if ${SUBSYS} == client
CONFLICTS=	isc-dhcp3?-client-[0-9]* isc-dhcp4[124]-client-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_CLIENT}
.elif ${SUBSYS} == relay
CONFLICTS=	isc-dhcp3?-relay-[0-9]* isc-dhcp4[124]-relay-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_RELAY}
.else
CONFLICTS=	isc-dhcp3?-server-[0-9]* isc-dhcp4[124]-server-[0-9]*
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

.include <bsd.port.options.mk>

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

.if ${PORT_OPTIONS:MPARANOIA}
CONFIGURE_ARGS+=--enable-paranoia --enable-early-chroot
SUB_LIST+=	PARANOIA="yes"
.else
SUB_LIST+=	PARANOIA="no"
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-ldap --with-ldapcrypto
USE_OPENLDAP=	yes
LDAP_SCRIPT=	${WRKSRC}/contrib/ldap/dhcpd-conf-to-ldap
LDAP_SCHEMA=	${WRKSRC}/contrib/ldap/dhcp.schema
LDAP_README=	${WRKSRC}/contrib/ldap/README.ldap
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIBS+=		-L${LOCALBASE}/lib
PORTDOCS+=	README.ldap
PLIST_SUB+=	SCHEMA_DIR="${SCHEMA_DIR:S,^${PREFIX}/,,}" LDAP=""
USES+=		shebangfix
SHEBANG_FILES=	contrib/ldap/dhcpd-conf-to-ldap
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP_SSL} && ${PORT_OPTIONS:MLDAP}
USES+=		ssl
CONFIGURE_ARGS+=--with-ldapcrypto
LIBS+=		-lssl
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-dhcpv6
PLIST_SUB+=	IPV6=""
.else
CONFIGURE_ARGS+=--disable-dhcpv6
PLIST_SUB+=	IPV6="@comment "
.endif

.if ${PORT_OPTIONS:MDHCP4O6}
CONFIGURE_ARGS+=--enable-dhcpv4o6
PLIST_SUB+=	DHCP4O6=""
.else
CONFIGURE_ARGS+=--disable-dhcpv4o6
PLIST_SUB+=	DHCP4O6="@comment "
.endif

.if ${PORT_OPTIONS:MBIND_SYMBOLS}
USES+=		perl5
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bind__Makefile
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
