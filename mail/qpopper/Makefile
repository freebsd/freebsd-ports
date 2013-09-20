# Created by: pst
# $FreeBSD$

PORTNAME=	qpopper
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/ \
		http://core.ring.gr.jp/archives/net/mail/qpopper/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	bc979@lafn.org
COMMENT=	Berkeley POP 3 server (now maintained by Qualcomm)

USE_AUTOTOOLS=	autoconf
USE_OPENSSL=	yes
CONFIGURE_ENV=	LIBS="-lcrypt -lmd -lutil -L${LOCALBASE}/lib" \
		OS_DEFS="-DSETPROCTITLE ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-nonauth-file=${POPUSERS_FILE} \
		--without-gdbm \
		--enable-keep-temp-drop

PLIST_SUB=	EPOPPASSD=${EPOPPASSD} \
		POP_USER=${POP_USER} \
		POP_GROUP=${POP_GROUP} \
		POP_MODE_DIR=${POP_MODE_DIR} \
		POP_MODE_CONF=${POP_MODE_CONF} \
		QPOPAUTH=${QPOPAUTH}

MAN8=		qpopper.8

SUB_FILES=	pkg-message

# internal configuration
POP_USER=	pop
POP_GROUP=	daemon
POP_MODE_DIR=	0711
POP_MODE_CONF=	0444
POPUSERS_FILE=	${ETCDIR}/popusers
SAMPLE_EXT=	.sample
#
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS_DEFINE=	APOP_ONLY APOP DOCUMENTATION DRAC FULL_POPD_DEBUG PAM \
	POPPASSD QPOPAUTH_SETUID SAMPLE_POPUSERS SHY_ENABLED \
	SSL STANDALONE_MODE U_OPTION

APOP_ONLY_DESC=	build with APOP authentication only
APOP_DESC=	build with APOP
DOCUMENTATION_DESC=	install pdf documentation
DRAC_DESC=	build with Dynamic Relay Authorization
FULL_POPD_DEBUG_DESC=	build with more verbose debugging
PAM_DESC=	build with PAM authentication
POPPASSD_DESC=	build the poppassd daemon
QPOPAUTH_SETUID_DESC=	install qpopauth setuid to pop user
SAMPLE_POPUSERS_DESC=	build a default reject file
SHY_ENABLED_DESC=	hide qpopper version in POP3 banner
SSL_DESC=	build with SSL/TLS support
STANDALONE_MODE_DESC=	build qpopper to be run without inetd
U_OPTION_DESC=	include support for user .qpopper-options

OPTIONS_DEFAULT=	APOP QPOPAUTH_SETUID SSL U_OPTION

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MAPOP)
QPOPAUTH=	"@comment "
.else
CONFIGURE_ARGS+=	--enable-apop=${ETCDIR}/pop.auth \
			--with-apopuid=pop
MAN8+=		qpopauth.8
QPOPAUTH=	""
# If WITH_APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentication only.
.if ${PORT_OPTIONS:MAPOP_ONLY}
OS_DEFS+=	-DAPOP_ONLY
.endif
.endif

# Do not install documentation since it is in pdf format and normally
# not used unless user wants it.
.if empty(PORT_OPTIONS:MDOCUMENTATION)
NOPORTDOCS=	yes
.endif

# If WITH_DRAC variable present in the environment, qpopper builds
# with Dynamic Relay Authorization Control support.
.if ${PORT_OPTIONS:MDRAC}
CONFIGURE_ARGS+=	--with-drac
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

# If WITH_FULL_POPD_DEBUG variable present in the environment, qpopper builds
# with more verbose debugging. See also -d option to qpopper.
.if ${PORT_OPTIONS:MFULL_POPD_DEBUG}
CONFIGURE_ARGS+=	--enable-debugging
.endif

# If WITH_PAM variable present qpopper builds with PAM authentication
.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam=pop3
.endif

# If WITH_POPPASSD variable present in the environment, qpopper builds
# with poppassd support.
.if ${PORT_OPTIONS:MPOPPASSD}
CONFIGURE_ARGS+=	--enable-poppassd
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-password::poppassd.c \
		${FILESDIR}/extra-patch-password::auth_user.c
EPOPPASSD=	""
.else
EPOPPASSD=	"@comment "
.endif

# If WITH_SHY_ENABLED variable present,  qpopper does not present
# its version number within the POP3 session.
.if ${PORT_OPTIONS:MSHY_ENABLED}
CONFIGURE_ARGS+=	--enable-shy
.endif

# If WITH STANDALONE_MODE variable present qpopper is built so it runs
# without inetd.
.if ${PORT_OPTIONS:MSTANDALONE_MODE}
CONFIGURE_ARGS+=	--enable-standalone
USE_RC_SUBR=	 ${PORTNAME}
.endif

# The default is to build without SSL/TLS support.
.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -f ${WRKSRC}/popper/md5.h
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/man/*
	@${REINPLACE_CMD} -e \
		's|\$${sbindir}/sendmail|${LOCALBASE}/sbin/sendmail|g' \
		${WRKSRC}/configure.in
.if defined(WITH_POPPASSD)
	@${REINPLACE_CMD} -e 's|/usr/bin/smbpasswd|${LOCALBASE}/bin/smbpasswd|' \
		${WRKSRC}/password/poppassd.c
.endif
.if defined(WITHOUT_U_OPTION)
	@${REINPLACE_CMD} -E -e 's|(getopt \(.+)u|\1|' \
		${WRKSRC}/popper/main.c
.endif

pre-configure:
	@(cd ${WRKSRC}; ${CHMOD} u+w configure*)

do-install:
.if !defined(WITHOUT_APOP)
	@${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${PREFIX}/bin/qpopauth
# If WITHOUT_QPOPAUTH_SETUID variable present in the environment,
# qpopper does not install qpopauth setuid to pop user so that
# anyone can access the pop.auth database.
.if !defined(WITHOUT_QPOPAUTH_SETUID)
	@${CHOWN} pop ${PREFIX}/bin/qpopauth
	@${CHMOD} u+s ${PREFIX}/bin/qpopauth
.endif
	@${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${MANPREFIX}/man/man8/qpopauth.8
	@${LN} -sf ${PREFIX}/bin/qpopauth ${PREFIX}/bin/qapopauth
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${PREFIX}/libexec/qpopper
	@${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${MANPREFIX}/man/man8/qpopper.8
.if defined(WITH_POPPASSD)
	@${INSTALL_PROGRAM} ${WRKSRC}/password/poppassd ${PREFIX}/libexec/qpoppassd
.endif
	@${INSTALL} -d -o ${POP_USER} -g ${POP_GROUP} -m ${POP_MODE_DIR} \
		${ETCDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/GUIDE.pdf ${DOCSDIR}
.endif

post-install: install-conf-file
	@${CAT} ${PKGMESSAGE}

# based on original from op port, written by Cyrille Lefevre
# <clefevre@citeweb.net>.
install-conf-file:
	@if [ ! -f ${CONF_DIR}/${CONF_FILE}${SAMP_SUFX} ]; then \
		if [ -f /etc/ftpusers ] && [ -n "${WITH_SAMPLE_POPUSERS}" ]; then \
			${INSTALL} -c -o ${POP_USER} -g ${POP_GROUP} -m ${POP_MODE_CONF} \
				/etc/ftpusers ${POPUSERS_FILE}${SAMPLE_EXT} ; \
		else \
			${CP} /dev/null ${POPUSERS_FILE}${SAMPLE_EXT} ; \
			${CHOWN} ${POP_USER}:${POP_GROUP} ${POPUSERS_FILE}${SAMPLE_EXT} ; \
			${CHMOD} ${POP_MODE_CONF} ${POPUSERS_FILE}${SAMPLE_EXT} ; \
		fi ; \
	fi
	@${INSTALL} -c -m 0640 \
		${WRKSRC}/samples/qpopper.config ${PREFIX}/etc/qpopper.config${SAMPLE_EXT}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
