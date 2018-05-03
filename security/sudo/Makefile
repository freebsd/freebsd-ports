# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	sudo
PORTVERSION=	1.8.23
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SUDO

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	sudo
LICENSE_NAME=	Sudo license
LICENSE_FILE=	${WRKSRC}/doc/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe libtool
CPE_VENDOR=	todd_miller
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-lgcc

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-logincap \
		--with-long-otp-prompt

OPTIONS_DEFINE=	LDAP INSULTS DISABLE_ROOT_SUDO DISABLE_AUTH NOARGS_SHELL \
		AUDIT OPIE PAM NLS SSSD DOCS EXAMPLES
OPTIONS_RADIO=	KERBEROS
OPTIONS_DEFAULT=	AUDIT PAM
OPTIONS_SUB=	yes

INSULTS_DESC=	Enable insults on failures
DISABLE_ROOT_SUDO_DESC=	Do not allow root to run sudo
DISABLE_AUTH_DESC=	Do not require authentication by default
NOARGS_SHELL_DESC=	Run a shell if no arguments are given
AUDIT_DESC=	Enable BSM audit support
KERBEROS_DESC=	Enable Kerberos 5 authentication (no PAM support)
OPIE_DESC=	Enable one-time passwords (no PAM support)
SSSD_DESC=	Enable SSSD backend support.

PAM_PREVENTS=	OPIE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
PAM_PREVENTS_MSG=	PAM cannot be combined with any other authentication plugin

LOGFAC?=	authpriv
CONFIGURE_ARGS+=	--with-logfac=${LOGFAC}

# This is intentionally not an option.
# SUDO_SECURE_PATH is a PATH string that will override the user's PATH.
# ex: make SUDO_SECURE_PATH="/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
.if defined(SUDO_SECURE_PATH)
CONFIGURE_ARGS+=	--with-secure-path="${SUDO_SECURE_PATH}"
.endif

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=	-L${LOCALBASE}/lib -lintl
NLS_CFLAGS=	-I${LOCALBASE}/include

INSULTS_CONFIGURE_ON=	--with-insults
INSULTS_CONFIGURE_ON+=	--with-all-insults

LDAP_USE=	OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${PREFIX}
SUDO_LDAP_CONF?=	ldap.conf
LDAP_CONFIGURE_ON+=	--with-ldap-conf-file=${PREFIX}/etc/${SUDO_LDAP_CONF}

DISABLE_ROOT_SUDO_CONFIGURE_ON=	--disable-root-sudo
DISABLE_AUTH_CONFIGURE_ON=	--disable-authentication
NOARGS_SHELL_CONFIGURE_ENABLE=	noargs-shell
AUDIT_CONFIGURE_WITH=	bsm-audit
PAM_CONFIGURE_ON=	--with-pam
OPIE_CONFIGURE_ON=	--with-opie
SSSD_CONFIGURE_ON=	--with-sssd
SSSD_RUN_DEPENDS=	sssd:security/sssd

OPTIONS_RADIO_KERBEROS=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-kerb5=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-kerb5=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-kerb5=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
# This is intentionally not an option.
# SUDO_KERB5_INSTANCE is an optional instance string that will be appended to kerberos
# principals when to perform authentication. Common choices are "admin" and "sudo".
.if defined(SUDO_KERB5_INSTANCE)
CONFIGURE_ARGS+=	--enable-kerb5-instance="${SUDO_KERB5_INSTANCE}"
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
CONFIGURE_ARGS+=	--disable-pie
.endif

post-patch:
	@${REINPLACE_CMD} -E '/install-(binaries|noexec):/,/^$$/ \
		s/\$$\(INSTALL\)/& ${STRIP}/;s/-b\~/-b ~/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(docdir),$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(bindir),' \
		${WRKSRC}/plugins/sudoers/Makefile.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/sudo.default
	${RM} ${STAGEDIR}${PREFIX}/etc/sudoers
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cvtsudoers
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sudoreplay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/visudo
.for f in group_file.so libsudo_util.so sudoers.so system_group.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/sudo/${f}
.endfor

.include <bsd.port.mk>
