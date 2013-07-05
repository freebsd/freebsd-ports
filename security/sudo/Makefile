# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	sudo
DISTVERSION=	1.8.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SUDO}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	sudo
LICENSE_NAME=	Sudo license
LICENSE_FILE=	${WRKSRC}/doc/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-lgcc
LDFLAGS+=	-lssp_nonshared

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-logincap \
		--with-long-otp-prompt

OPTIONS_DEFINE=	LDAP INSULTS DISABLE_ROOT_SUDO DISABLE_AUTH NOARGS_SHELL \
		AUDIT OPIE NLS
OPTIONS_DEFAULT=	AUDIT NLS

INSULTS_DESC=	Enable insults on failures
DISABLE_ROOT_SUDO_DESC=	Do not allow root to run sudo
DISABLE_AUTH_DESC=	Do not require authentication by default
NOARGS_SHELL_DESC=	Run a shell if no arguments are given
AUDIT_DESC=	Enable BSM audit support
OPIE_DESC=	Enable one-time passwords (no PAM support)

LOGFAC?=	local2
CONFIGURE_ARGS+=	--with-logfac=${LOGFAC}

# This is intentionally not an option.
# SUDO_SECURE_PATH is a PATH string that will override the user's PATH.
# ex: make SUDO_SECURE_PATH="/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
.if defined(SUDO_SECURE_PATH)
CONFIGURE_ARGS+=	--with-secure-path="${SUDO_SECURE_PATH}"
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
CONFIGURE_ARGS+=	--disable-pie
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MINSULTS}
CONFIGURE_ARGS+=	--with-insults
CONFIGURE_ARGS+=	--with-all-insults
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${PREFIX}
SUDO_LDAP_CONF?=	ldap.conf
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/${SUDO_LDAP_CONF}
PLIST_SUB+=	LDAP=""
MAN5+=	sudoers.ldap.5
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MDISABLE_ROOT_SUDO}
CONFIGURE_ARGS+=--disable-root-sudo
.endif

.if ${PORT_OPTIONS:MDISABLE_AUTH}
CONFIGURE_ARGS+=	--disable-authentication
.endif

.if ${PORT_OPTIONS:MNOARGS_SHELL}
CONFIGURE_ARGS+=	--enable-noargs-shell
.endif

.if ${PORT_OPTIONS:MAUDIT}
CONFIGURE_ARGS+=	--with-bsm-audit
.endif

.if ${PORT_OPTIONS:MOPIE}
CONFIGURE_ARGS+=	--with-opie
.else
CONFIGURE_ARGS+=	--with-pam
.endif

MAN5+=		sudoers.5 sudo.conf.5
MAN8=		sudo.8 visudo.8 sudoreplay.8 sudo_plugin.8
MLINKS=		sudo.8 sudoedit.8

post-patch:
	@${REINPLACE_CMD} -E '/install-(binaries|noexec):/,/^$$/ \
		s/\$$\(INSTALL\)/& ${STRIP}/;s/-b\~/-b ~/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(docdir),$$(srcdir)/sudoers2ldif $$(DESTDIR)$$(bindir),' ${WRKSRC}/plugins/sudoers/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's/mkinstalldirs $$(DESTDIR)$$(docdir)/mkinstalldirs/' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/for f in $$(OTHER_DOCS); do/d;/@LDAP@for f in $$(OTHER_DOCS_LDAP); do/d' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's/$$(DESTDIR)$$(sudoersdir) $$(DESTDIR)$$(docdir)/$$(DESTDIR)$$(sudoersdir)/' ${WRKSRC}/plugins/sudoers/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/sudo.default
	if [ ! -f ${PREFIX}/etc/pam.d/sudo ]; then \
		${CP} -p ${PREFIX}/etc/pam.d/sudo.default \
		${PREFIX}/etc/pam.d/sudo ; \
	fi
	if [ ! -f ${PREFIX}/etc/sudoers ]; then \
		${CP} -p ${PREFIX}/etc/sudoers.sample ${PREFIX}/etc/sudoers; \
	fi
	${TOUCH} ${PREFIX}/etc/sudoers.d/.keep-me

.include <bsd.port.mk>
