# Ports collection Makefile for:	nss_ldapd
# Date created:				23/7/2009
# Whom:					melifaro@ipfw.ru
#
# $FreeBSD$
#

PORTNAME=		nss-pam-ldapd
PORTVERSION=		0.8.6
CATEGORIES=		net
MASTER_SITES=		http://arthurdejong.org/nss-pam-ldapd/ \
			http://static.ipfw.ru/files/

MAINTAINER=		rflynn@acsalaska.net
COMMENT=		Advanced fork of nss_ldap

LICENSE=		LGPL21 LGPL3
LICENSE_COMB=		dual

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_OPENLDAP=		yes
USE_RC_SUBR=		nslcd
PAM_LDAP_SHMAJOR=	1
NSS_LDAP_SHMAJOR=	1

NSLCD_PIDFILE?=		/var/run/nslcd.pid
NSLCD_SOCKET?=		/var/run/nslcd.ctl

OPTIONS=		SASL		"Enable SASL" off \
			PAM		"Build pam_ldap" on

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
PLIST_SUB+=		CONFIG=${CONFIG_FILE}

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
.else
CONFIGURE_ARGS+=	--enable-nss
CONFLICTS+=		nss_ldap-1.*
PLIST_SUB+=		NSS=""
.endif

.if defined(WITHOUT_NSLCD)
CONFIGURE_ARGS+=	--disable-nslcd
PLIST_SUB+=		NSLCD="@comment "
.else
CONFIGURE_ARGS+=	--enable-nslcd
PLIST_SUB+=		NSLCD=""
MAN5+=			nslcd.conf.5
MAN8+=			nslcd.8
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/\(INSTALL_\)\(.*\)) -D /\1\2) /' ${WRKSRC}/Makefile.in ${WRKSRC}/nss/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's/^\(CFLAGS.*\) \-O2 \(.*\)$$/\1 -O0 \2/' ${WRKSRC}/nss/Makefile

post-install:
.if !defined(WITHOUT_NSS)
	@cd ${PREFIX}/lib && ${LN} -fs nss_ldap.so.${NSS_LDAP_SHMAJOR} \
		nss_ldap.so
.endif
.if !defined(WITHOUT_PAM)
	@cd ${PREFIX}/lib && ${LN} -fs pam_ldap.so.${PAM_LDAP_SHMAJOR} \
		pam_ldap.so
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}
	@${ECHO_MSG} " LDAP configuration:      ${PREFIX}/etc/${CONFIG_FILE}"
	@${ECHO_MSG} " Sample configuration:    ${PREFIX}/etc/${CONFIG_FILE}.sample"
	@${ECHO_MSG}
.if !defined(WITHOUT_NSS)
	@${ECHO_MSG} " WARNING: Be sure to set uid and gid configuration parameters"
	@${ECHO_MSG} " WARNING: to make nslcd run under unprivileged user"
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}

.include <bsd.port.mk>
