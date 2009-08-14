# Ports collection Makefile for:	nss_ldapd
# Date created:				23/7/2009
# Whom:					melifaro@ipfw.ru
#
# $FreeBSD$
#

PORTNAME=		nss_ldapd
PORTVERSION=		0.6.11
CATEGORIES=		net
MASTER_SITES=		http://arthurdejong.org/nss-ldapd/
DISTNAME=		nss-ldapd-${PORTVERSION}

MAINTAINER=		melifaro@ipfw.ru
COMMENT=		Advanced fork of nss_ldap

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
USE_OPENLDAP=		yes
USE_RC_SUBR=		nslcd

NSLCD_PIDFILE?=		/var/run/nslcd.pid
NSLCD_SOCKET?=		/var/run/nslcd.ctl

OPTIONS=		NSS_COMPAT	"Enable nss_ldap compatibility" on \
			SASL		"Enable SASL" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=			problems with nss/libc TLS
.endif

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS+=	--with-nslcd-pidfile=${NSLCD_PIDFILE} \
			--with-nslcd-socket=${NSLCD_SOCKET} \
			--with-ldap-lib=openldap --disable-kerberos

.if defined(WITHOUT_NSS)
.undef NSS_COMPAT
.endif

.if defined(WITH_NSS_COMPAT)
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf
PLIST_SUB+=		CONFIG="nss_ldap"
EXTRA_PATCHES+=		${PATCHDIR}/nss_compat.diff
.else
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldapd.conf
PLIST_SUB+=		CONFIG="nss_ldapd"
.endif

.if defined(WITH_SASL)
WANT_OPENLDAP_SASL=	yes
CONFIGURE_ARGS+=	--enable-sasl
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
.else
CONFIGURE_ARGS+=	--disable-pam
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
MAN8=			nslcd.8
.endif

MAN5=			nss-ldapd.conf.5

post-extract:
	@${REINPLACE_CMD} -e 's/\(INSTALL_\)\(.*\)) -D /\1\2) /' ${WRKSRC}/Makefile.in ${WRKSRC}/nss/Makefile.in
	@${REINPLACE_CMD} -e 's/shadow.$$(OBJEXT)/shadow.$$(OBJEXT) bsdnss.$$(OBJEXT)/;s/shadow\.c/shadow.c bsdnss.c/;s/exports\.linux/exports.freebsd/' ${WRKSRC}/nss/Makefile.in
	@${REINPLACE_CMD} -e 's/^NSS_VERS = .*/NSS_VERS = 1/;s/libnss_ldap\.so/nss_ldap.so/' ${WRKSRC}/nss/Makefile.in
	@${MV} ${WRKSRC}/nss/exports.linux ${WRKSRC}/nss/exports.freebsd
	@${REINPLACE_CMD} -e 's/$$(DESTDIR)$$(NSS_LDAP_PATH_CONF)/$$(DESTDIR)$$(NSS_LDAP_PATH_CONF).sample/' ${WRKSRC}/Makefile.in

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}
.if defined(WITH_NSS_COMPAT)
	@${ECHO_MSG} "                NSS_LDAP compatibility ENABLED."
	@${ECHO_MSG}
	@${ECHO_MSG} " LDAP configuration:      ${PREFIX}/etc/nss_ldap.conf"
	@${ECHO_MSG} " Secret file:             ${PREFIX}/etc/nss_ldap.secret"
	@${ECHO_MSG} " Sample configuration:    ${PREFIX}/etc/nss_ldap.conf.sample"
	@${ECHO_MSG}
	@${ECHO_MSG} " Check if you need to adjust  reconnect_* parameters"
	@${ECHO_MSG} " WARNING: nss_ldapd will use ONLY rootbinddn to access LDAP data"
.else
	@${ECHO_MSG} " LDAP configuration:      ${PREFIX}/etc/nss_ldapd.conf"
	@${ECHO_MSG} " Sample configuration:    ${PREFIX}/etc/nss_ldapd.conf.sample"
	@${ECHO_MSG}
.endif
.if !defined(WITHOUT_NSS)
	@${ECHO_MSG} " WARNING: Be sure to set uid and gid configuration parameters"
	@${ECHO_MSG} " WARNING: to make nslcd run under unprivileged user"
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}

.include <bsd.port.post.mk>
