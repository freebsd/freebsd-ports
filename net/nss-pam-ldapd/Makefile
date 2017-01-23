# Created by: melifaro@ipfw.ru
# $FreeBSD$

PORTNAME=		nss-pam-ldapd
PORTVERSION=		0.9.7
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://arthurdejong.org/nss-pam-ldapd/ \
			http://mirrors.rit.edu/zi/

MAINTAINER?=		zi@FreeBSD.org
COMMENT?=		Advanced fork of nss_ldap

LICENSE=		LGPL21 LGPL3
LICENSE_COMB=		dual

USES=			cpe
CPE_VENDOR=		arthurdejong
GNU_CONFIGURE=		yes
USE_OPENLDAP=		yes
USE_RC_SUBR=		nslcd
PAM_LDAP_SHMAJOR=	1
NSS_LDAP_SHMAJOR=	1
PKGMESSAGE=		${WRKDIR}/pkg-message
SUB_FILES+=		pkg-message

NSLCD_PIDFILE?=		/var/run/nslcd.pid
NSLCD_SOCKET?=		/var/run/nslcd.ctl

OPTIONS_DEFINE=		KERBEROS
OPTIONS_DEFAULT=	KERBEROS

.if defined(SLAVE_PORT)
OPTIONS_DEFINE+=	SASL
OPTIONS_MULTI=		MG1
OPTIONS_MULTI_MG1=	PAM NSS
PAM_DESC=		Build pam_ldap
NSS_DESC=		Build nss support
SASL_DESC=		Build sasl support
OPTIONS_DEFAULT+=	PAM NSS
CONFLICTS+=		nss-pam-ldapd-[0-9]*
.else
OPTIONS_MULTI=		MG1
OPTIONS_MULTI_MG1=	PAM NSS
PAM_DESC=		Build pam_ldap
NSS_DESC=		Build nss support
OPTIONS_DEFAULT+=	PAM NSS
CONFLICTS+=		nss-pam-ldapd-sasl-[0-9]*
.endif

USERS=			nslcd
GROUPS=			nslcd

.include <bsd.port.options.mk>

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-nslcd-pidfile=${NSLCD_PIDFILE} \
			--with-nslcd-socket=${NSLCD_SOCKET} \
			--with-ldap-lib=openldap \
			--with-nss-ldap-soname=nss_ldap.so.${NSS_LDAP_SHMAJOR}

CONFIG_FILE=		"nslcd.conf"
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/${CONFIG_FILE}
PLIST_SUB+=		CONFIG="${CONFIG_FILE}" \
			PAM_LDAP_SHMAJOR="${PAM_LDAP_SHMAJOR}" \
			NSS_LDAP_SHMAJOR="${NSS_LDAP_SHMAJOR}"
SUB_LIST+=		CONFIG_FILE="${PREFIX}/etc/${CONFIG_FILE}" \
			NSLCD_PIDFILE="${NSLCD_PIDFILE}"

.if empty(PORT_OPTIONS:MKERBEROS)
CONFIGURE_ARGS+=	--disable-kerberos
.endif

.if ${PORT_OPTIONS:MSASL}
WANT_OPENLDAP_SASL=	yes
CONFIGURE_ARGS+=	--enable-sasl
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam \
			--with-pam-seclib-dir=${PREFIX}/lib \
			--with-pam-ldap-soname=pam_ldap.so.${PAM_LDAP_SHMAJOR}
CONFLICTS+=		pam_ldap-1.*
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		PAM="@comment "
.endif

.if ${PORT_OPTIONS:MNSS}
CONFIGURE_ARGS+=	--enable-nss
CONFLICTS+=		nss_ldap-1.*
PLIST_SUB+=		NSS=""
SUB_LIST+=		NSS_MESSAGE="WARNING: Be sure to set uid and gid configuration parameters to make nslcd run under unprivileged user."
.else
CONFIGURE_ARGS+=	--disable-nss
PLIST_SUB+=		NSS="@comment "
SUB_LIST+=		NSS_MESSAGE=""
.endif

# Won't hook this in to OPTIONS until PADL ports are at least DEPRECATED.
# It doesn't do the software any good to run as replacement for the PADL ports
# without running the daemon.
.if defined(WITHOUT_NSLCD)
CONFIGURE_ARGS+=	--disable-nslcd
PLIST_SUB+=		NSLCD="@comment "
.else
CONFIGURE_ARGS+=	--enable-nslcd
PLIST_SUB+=		NSLCD=""
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/\(INSTALL_\)\(.*\)) -D /\1\2) /' ${WRKSRC}/Makefile.in ${WRKSRC}/nss/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's/^\(CFLAGS.*\) \-O2 \(.*\)$$/\1 -O0 \2/' ${WRKSRC}/nss/Makefile

post-install:
.if ${PORT_OPTIONS:MNSS}
	@${LN} -fs nss_ldap.so.${NSS_LDAP_SHMAJOR} ${STAGEDIR}${PREFIX}/lib/nss_ldap.so
.endif
.if ${PORT_OPTIONS:MPAM}
	@${LN} -fs pam_ldap.so.${PAM_LDAP_SHMAJOR} ${STAGEDIR}${PREFIX}/lib/pam_ldap.so
.endif

.include <bsd.port.mk>
