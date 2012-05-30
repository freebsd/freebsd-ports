# Ports collection Makefile for:	nss_ldapd
# Date created:				23/7/2009
# Whom:					melifaro@ipfw.ru
#
# $FreeBSD$
#
# vim: ft=pmake tw=78 fo=cq
#

PORTNAME=		nss-pam-ldapd
PORTVERSION=		0.8.9
CATEGORIES=		net
MASTER_SITES=		http://arthurdejong.org/nss-pam-ldapd/

MAINTAINER?=		rflynn@acsalaska.net
COMMENT?=		Advanced fork of nss_ldap

LICENSE=		LGPL21 LGPL3
LICENSE_COMB=		dual

GNU_CONFIGURE=		yes
# Gmake seems to be not really needed anymore.
# Gmake specific constructs are limited to maintainer targets
# USE_GMAKE=		yes
USE_OPENLDAP=		yes
USE_RC_SUBR=		nslcd
PAM_LDAP_SHMAJOR=	1
NSS_LDAP_SHMAJOR=	1
PKGMESSAGE=		${WRKDIR}/pkg-message
SUB_FILES+=		pkg-message

NSLCD_PIDFILE?=		/var/run/nslcd.pid
NSLCD_SOCKET?=		/var/run/nslcd.ctl

.if defined(SLAVE_PORT)
OPTIONS=		PAM		"Build pam_ldap" on \
			NSS		"Build nss support" on
WITH_SASL=yes
CONFLICTS+=		nss-pam-ldapd-[0-9]*
.else
OPTIONS=		NSS		"Build nss support" on \
			PAM		"Build pam_ldap" on
CONFLICTS+=		nss-pam-ldapd-sasl-[0-9]*
.endif

USERS=			nslcd
GROUPS=			nslcd

.include <bsd.port.options.mk>

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-nslcd-pidfile=${NSLCD_PIDFILE} \
			--with-nslcd-socket=${NSLCD_SOCKET} \
			--with-ldap-lib=openldap --disable-kerberos \
			--with-nss-ldap-soname=nss_ldap.so.${NSS_LDAP_SHMAJOR}

CONFIG_FILE=		"nslcd.conf"
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/${CONFIG_FILE}
PLIST_SUB+=		CONFIG="${CONFIG_FILE}"
SUB_LIST+=		CONFIG_FILE="${PREFIX}/etc/${CONFIG_FILE}"

.if defined(WITH_SASL)
WANT_OPENLDAP_SASL=	yes
CONFIGURE_ARGS+=	--enable-sasl
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam \
			--with-pam-seclib-dir=${PREFIX}/lib \
			--with-pam-ldap-soname=pam_ldap.so.${PAM_LDAP_SHMAJOR}
MAN8+=			pam_ldap.8
CONFLICTS+=		pam_ldap-1.*
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		PAM="@comment "
.endif

.if defined(WITHOUT_NSS)
CONFIGURE_ARGS+=	--disable-nss
PLIST_SUB+=		NSS="@comment "
SUB_LIST+=		NSS_MESSAGE=""
.else
CONFIGURE_ARGS+=	--enable-nss
CONFLICTS+=		nss_ldap-1.*
PLIST_SUB+=		NSS=""
SUB_LIST+=		NSS_MESSAGE="WARNING: Be sure to set uid and gid configuration parameters to make nslcd run under unprivileged user."
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
MAN5+=			nslcd.conf.5
MAN8+=			nslcd.8
.endif

.if defined(WITHOUT_NSS) && defined(WITHOUT_PAM)
BROKEN=	Software is useless if both NSS and PAM are disabled.\
	Rerun 'make config' or 'portmaster --force-config'.
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/\(INSTALL_\)\(.*\)) -D /\1\2) /' ${WRKSRC}/Makefile.in ${WRKSRC}/nss/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's/^\(CFLAGS.*\) \-O2 \(.*\)$$/\1 -O0 \2/' ${WRKSRC}/nss/Makefile

show-pkgmessage::
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE} | ${FMT} 75 79; ${ECHO_CMD}

# We take care of the sample file, upstream install target installs the actual
# file if it does not exist yet.
post-install: show-pkgmessage
	@${INSTALL_DATA} ${WRKSRC}/nslcd.conf ${PREFIX}/etc/nslcd.conf.sample
.if !defined(WITHOUT_NSS)
	@${LN} -fs nss_ldap.so.${NSS_LDAP_SHMAJOR} ${PREFIX}/lib/nss_ldap.so
.endif
.if !defined(WITHOUT_PAM)
	@${LN} -fs pam_ldap.so.${PAM_LDAP_SHMAJOR} ${PREFIX}/lib/pam_ldap.so
.endif

.include <bsd.port.mk>
