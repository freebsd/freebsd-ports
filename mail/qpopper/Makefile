# New ports collection makefile for:	qpopper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	4.0.4
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME}${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	qpopper4.0.4-ipv6-20020502.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	lioux@FreeBSD.org

USE_AUTOCONF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd -lutil -L${LOCALBASE}/lib" \
		OS_DEFS="-DSETPROCTITLE ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
		--enable-nonauth-file=${POPUSERS_FILE} \
		--with-apopuid=pop --without-gdbm \
		--enable-keep-temp-drop

PLIST_SUB=	EPOPPASSD=${EPOPPASSD} \
		POP_USER=${POP_USER} \
		POP_GROUP=${POP_GROUP} \
		POP_MODE_DIR=${POP_MODE_DIR} \
		POP_MODE_CONF=${POP_MODE_CONF}

MAN8=		qpopauth.8 qpopper.8

# internal configuration
POP_USER=	pop
POP_GROUP=	daemon
POP_MODE_DIR=	0711
POP_MODE_CONF=	0444
POPUSERS_FILE=	${PREFIX}/etc/qpopper/popusers
SAMPLE_EXT=	.sample
#
PKGDEINSTALL=	${PKGINSTALL}

pre-everything::
.if defined(APOP_ONLY)
	@${ECHO_MSG} "==> The APOP_ONLY option is deprecated, please use"
	@${ECHO_MSG} "	WITH_APOP_ONLY instead."
	@${ECHO_MSG} "==> The APOP_ONLY option will work in this version but"
	@${ECHO_MSG} "	not on future ones."
.endif
.if defined(FULL_POPD_DEBUG)
	@${ECHO_MSG} "==> The FULL_POPD_DEBUG option is deprecated, please"
	@${ECHO_MSG} "	use WITH_FULL_POPD_DEBUG instead."
	@${ECHO_MSG} "==> The FULL_POPD_DEBUG option will work in this version but"
	@${ECHO_MSG} "	not on future ones."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_APOP_ONLY=yes	builds with APOP authentication only"
	@${ECHO_MSG} "WITH_DOCUMENTATION=yes	installs pdf documentation"
	@${ECHO_MSG} "WITH_DRAC=yes		builds with Dynamic Relay Authorization"
	@${ECHO_MSG} "				Control support"
	@${ECHO_MSG} "WITHOUT_IPV6=yes          builds without IPv6 support"
	@${ECHO_MSG} "WITH_FULL_POPD_DEBUG=yes	builds with more verbose debugging"
	@${ECHO_MSG} "WITH_PAM=yes              builds with PAM authentication"
	@${ECHO_MSG} "WITH_POPPASSD=yes		builds the poppassd daemon"
	@${ECHO_MSG} "WITHOUT_QPOPAUTH_SETUID=yes  does not install qpopauth setuid to pop user"
	@${ECHO_MSG} "WITH_SAMPLE_POPUSERS_FILE=yes	builds a default (otherwise,"
	@${ECHO_MSG} "				use an empty file) reject file"
	@${ECHO_MSG} "WITH_STANDALONE_MODE=yes  builds qpopper to be run without inetd"
	@${ECHO_MSG} "WITHOUT_U_OPTION=yes      forbids daemon command line option"
	@${ECHO_MSG} "                 -u which allows, after a user authenticates,"
	@${ECHO_MSG} "                 process options to be read from a file called"
	@${ECHO_MSG} "                 .qpopper-options in the user's home directory"
	@${ECHO_MSG} "                 This file can be owned by and writable by the"
	@${ECHO_MSG} "                 user. If improperly written, may cause a buffer"
	@${ECHO_MSG} "                 overflow which may remove such user's mail box"
	@${ECHO_MSG} "WITH_Y_OPTION=yes		enables daemon command line option"
	@${ECHO_MSG} "			-y which allows the user to specify a different"
	@${ECHO_MSG} "			logging facility"

# If WITH_APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentication only.
.if defined(APOP_ONLY) || defined(WITH_APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif

# Do not install documentation since it is in pdf format and normally
# not used unless user wants it
.if !defined(WITH_DOCUMENTATION)
NOPORTDOCS=	yes
.endif

# If WITH_DRAC variable present in the environment, qpopper builds
# with Dynamic Relay Authorization Control support
.if defined(WITH_DRAC)
CONFIGURE_ARGS+=	--with-drac
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

# If WITH_FULL_POPD_DEBUG variable present in the environment, qpopper builds
# with more verbose debugging. See also -d option to qpopper
.if defined(FULL_POPD_DEBUG) || defined(WITH_FULL_POPD_DEBUG)
CONFIGURE_ARGS+=	--enable-debugging
.endif

# If WITH_PAM variable present qpopper builds with PAM authentication
.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam=pop3
.endif

# If WITH_POPPASSD variable present in the environment, qpopper builds
# with poppassd support.
.if defined(WITH_POPPASSD)
CONFIGURE_ARGS+=	--enable-poppassd
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-password::poppassd.c
EPOPPASSD=	""
.else
EPOPPASSD=	"@comment "
.endif

# If WITH STANDALONE_MODE variable present qpopper is built so it runs
# without inetd
.if defined(WITH_STANDALONE_MODE)
CONFIGURE_ARGS+=	--enable-standalone
.endif

# If WITH_Y_OPTION variable present, qoppper daemon will
# accept -y command line option which allows the user to specify a
# different logging facility
.if defined(WITH_Y_OPTION)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-popper::pop_init.c
.endif

.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
CONFIGURE_ARGS+=	--with-openssl=/usr
.elif exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
LIB_DEPENDS+=	ssl.3:${PORTSDIR}/security/openssl
CONFIGURE_ARGS+=	-with-includes=${LOCALBASE}/include/openssl --with-openssl=${LOCALBASE}
CONFIGURE_ENV+=	RSAGLUE="${RSAGLUE}"
.if exists(${LOCALBASE}/lib/librsaref.a)
RSAGLUE=	-lrsaref
.endif
RSAGLUE+=	-lRSAglue
.endif

post-patch:
	@${RM} -f ${WRKSRC}/popper/md5.h
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/man/*
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
	@${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${PREFIX}/bin/qpopauth
# If WITHOUT_QPOPAUTH_SETUID variable present in the environment,
# qpopper does not install qpopauth setuid to pop user so that
# anyone can access the pop.auth database.
.if !defined(WITHOUT_QPOPAUTH_SETUID)
	@${CHOWN} pop ${PREFIX}/bin/qpopauth
	@${CHMOD} u+s ${PREFIX}/bin/qpopauth
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${PREFIX}/libexec/qpopper
	@${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${MANPREFIX}/man/man8/qpopauth.8
	@${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${MANPREFIX}/man/man8/qpopper.8
	@${LN} -sf ${PREFIX}/bin/qpopauth ${PREFIX}/bin/qapopauth
.if defined(WITH_POPPASSD)
	@${INSTALL_PROGRAM} ${WRKSRC}/password/poppassd ${PREFIX}/libexec/qpoppassd
.endif
	@${INSTALL} -d -o ${POP_USER} -g ${POP_GROUP} -m ${POP_MODE_DIR} \
		${PREFIX}/etc/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/GUIDE.pdf ${DOCSDIR}
.endif

post-install: install-conf-file
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

# based on original from op port, written by Cyrille Lefevre
# <clefevre@citeweb.net>
install-conf-file:
	@if [ ! -f ${CONF_DIR}/${CONF_FILE}${SAMP_SUFX} ]; then \
		if [ -f /etc/ftpusers ] && [ -n "${WITH_SAMPLE_POPUSERS_FILE}" ]; then \
			${INSTALL} -c -o ${POP_USER} -g ${POP_GROUP} -m ${POP_MODE_CONF} \
				/etc/ftpusers ${POPUSERS_FILE}${SAMPLE_EXT} ; \
		else \
			${CP} /dev/null ${POPUSERS_FILE}${SAMPLE_EXT} ; \
			${CHOWN} ${POP_USER}:${POP_GROUP} ${POPUSERS_FILE}${SAMPLE_EXT} ; \
			${CHMOD} ${POP_MODE_CONF} ${POPUSERS_FILE}${SAMPLE_EXT} ; \
		fi ; \
	fi
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
