# $FreeBSD$

PORTNAME=	dhcp
DISTVERSION=	4.1-ESV
PORTREVISION=	${DHCP_PORTREVISION}
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	ISC/${PORTNAME}/${DISTVERSION}-${PATCHLEVEL}
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	41-${SUBSYS}
DISTFILES=	${PORTNAME}-${DISTVERSION}-${PATCHLEVEL}${EXTRACT_SUFX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT?=	The ISC Dynamic Host Configuration Protocol server

LICENSE=	ISCL

PATCHLEVEL=	R12-P1
PORTREVISION_SERVER=	10
PORTREVISION_CLIENT=	3
PORTREVISION_RELAY=	6

DEPRECATED=	isc-dhcp 4.1 is now End of Life
EXPIRATION_DATE=	2016-03-01

SUBSYS?=	server
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-${PATCHLEVEL}

OPTIONS_DEFINE=	IPV6

.if ${SUBSYS} == server
OPTIONS_DEFINE+=	PARANOIA LDAP LDAP_SSL
OPTIONS_DEFAULT+=	PARANOIA LDAP_SSL
PARANOIA_DESC=	Enable support for chroot
LDAP_SSL_DESC=	Support LDAP over SSL/TLS
.endif

# PORTREVISION and CONFLICTS handling
.if ${SUBSYS} == client
CONFLICTS=	isc-dhcp3?-client* isc-dhcp4[2-9]-client*
DHCP_PORTREVISION=	${PORTREVISION_CLIENT}
.elif ${SUBSYS} == relay
CONFLICTS=	isc-dhcp3?-relay* isc-dhcp4[2-9]-relay*
DHCP_PORTREVISION=	${PORTREVISION_RELAY}
.else
CONFLICTS=	isc-dhcp3?-server* isc-dhcp4[2-9]-server*
DHCP_PORTREVISION=	${PORTREVISION_SERVER}
.endif

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
CONFIGURE_ARGS+=	--localstatedir=/var
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

# XXX: Have to hardcode 4.1.1 here as there is no release for 4.1.2 or later.
.if ${PORT_OPTIONS:MLDAP}
MASTER_SITES+=		http://cloud.github.com/downloads/dcantrell/ldap-for-dhcp/:ldap
LDAPPATCHRELEASE=	2
LDAPPATCHDIST=		ldap-for-dhcp-4.1.1-${LDAPPATCHRELEASE}
LDAPPATCHFILE=		dhcp-4.1.1-ldap.patch
DISTFILES+=		${LDAPPATCHDIST}.tar.gz:ldap
PLIST_SUB+=		SCHEMA_DIR="${SCHEMA_DIR:S,^${PREFIX}/,,}" LDAP=""
PORTDOCS+=		README.ldap LICENSE.ldap
LDAP_SCRIPT=		${WRKDIR}/${LDAPPATCHDIST}/dhcpd-conf-to-ldap
LDAP_SCHEMA=		${WRKDIR}/${LDAPPATCHDIST}/dhcp.schema
USES+=			autoreconf perl5
USE_PERL5=		run
USE_OPENLDAP=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-ldap
.else
PLIST_SUB+=	LDAP="@comment "
.endif

# WITH_DHCP_LDAP_SSL without WITH_DHCP_LDAP is silly.
.if ${PORT_OPTIONS:MLDAP_SSL} && ${PORT_OPTIONS:MLDAP}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ldapcrypto
LIBS+=		-lssl
# hack to get bsd.openssl.mk included at this late state
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if ${PORT_OPTIONS:MPARANOIA}
CONFIGURE_ARGS+=	--enable-paranoia --enable-early-chroot
SUB_LIST+=		PARANOIA="yes"
.else
SUB_LIST+=		PARANOIA="no"
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-dhcpv6
PLIST_SUB+=		IPV6=""
.else
CONFIGURE_ARGS+=	--disable-dhcpv6
PLIST_SUB+=		IPV6="@comment "
.endif

pre-patch:
.if ${SUBSYS} == server && ${PORT_OPTIONS:MLDAP}
	@${PATCH} ${WRKDIR}/${LDAPPATCHDIST}/${LDAPPATCHFILE} ${FILESDIR}/extra-patch-${LDAPPATCHFILE}
	@cd ${WRKSRC} && ${PATCH} -p1 < ${WRKDIR}/${LDAPPATCHDIST}/${LDAPPATCHFILE}
.endif

post-patch:
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/client/dhclient.conf.example

do-install:
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/${SUBSYS} install
.if ${SUBSYS} == server
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/dhcpctl install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/dst install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/omapip install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/includes install
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/common install
	${INSTALL_DATA} ${WRKSRC}/dhcpctl/dhcpctl.h ${STAGEDIR}${PREFIX}/include
.if ${PORT_OPTIONS:MIPV6}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/dhcpd-dhcpv6.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpd6.conf.sample
.endif
.endif
.if ${PORT_OPTIONS:MLDAP}
	@${MKDIR} ${STAGEDIR}${SCHEMA_DIR}
	${INSTALL_DATA} ${LDAP_SCHEMA} ${STAGEDIR}${SCHEMA_DIR}
	${INSTALL_SCRIPT} ${LDAP_SCRIPT} ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLDAP}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${LDAPPATCHDIST}/README.ldap  ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${LDAPPATCHDIST}/LICENSE.ldap ${STAGEDIR}${DOCSDIR}
.endif

post-install:
.if ${SUBSYS} == client
	${INSTALL_SCRIPT} ${WRKSRC}/client/scripts/freebsd ${STAGEDIR}${PREFIX}/sbin/dhclient-script
	${MV} ${STAGEDIR}${PREFIX}/etc/dhclient.conf.example ${STAGEDIR}${PREFIX}/etc/dhclient.conf.sample
.elif ${SUBSYS} == server
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpd.conf.example ${STAGEDIR}${PREFIX}/etc/dhcpd.conf.sample
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
.if ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} -e 's|^%%LDAP%%||g' ${PKGMESSAGE}
.else
	@${REINPLACE_CMD} -e '/^%%LDAP%%/d' ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
