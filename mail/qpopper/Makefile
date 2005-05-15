# New ports collection makefile for:	qpopper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	4.0.8
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/ \
		http://core.ring.gr.jp/archives/net/mail/qpopper/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Berkeley POP 3 server (now maintained by Qualcomm)

USE_AUTOCONF_VER=	259
USE_REINPLACE=	yes
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

# internal configuration
POP_USER=	pop
POP_GROUP=	daemon
POP_MODE_DIR=	0711
POP_MODE_CONF=	0444
POPUSERS_FILE=	${PREFIX}/etc/qpopper/popusers
SAMPLE_EXT=	.sample
#
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	APOP_ONLY	"build with APOP authentication only" off \
		APOP		"build with APOP" on \
		DOCUMENTATION	"install pdf documentation" off \
		DRAC		"build with Dynamic Relay Authorization" off \
		IPV6		"build with IPv6 support" on \
		FULL_POPD_DEBUG	"build with more verbose debugging" off \
		PAM		"build with PAM authentication" off \
		POPPASSD	"build the poppassd daemon" off \
		QPOPAUTH_SETUID	"install qpopauth setuid to pop user" on \
		SAMPLE_POPUSERS	"build a default reject file" off \
		SHY_ENABLED	"hide qpopper version in POP3 banner" off \
		SSL		"build with SSL/TLS support" on \
		STANDALONE_MODE	"build qpopper to be run without inetd" off \
		U_OPTION	"include support for user .qpopper-options" on

.include <bsd.port.pre.mk>

.if  ${OSVERSION} < 400014
WITHOUT_IPV6=	yes
.endif

.if !defined(WITHOUT_IPV6)
PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	qpopper4.0.8-ipv6-20050515.diff.gz
PATCH_DIST_STRIP=	-p1
.endif

.if defined(WITHOUT_APOP)
QPOPAUTH=	"@comment "
.else
CONFIGURE_ARGS+=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
			--with-apopuid=pop
MAN8+=		qpopauth.8
QPOPAUTH=	""
# If WITH_APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentication only.
.if defined(WITH_APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif
.endif

# Do not install documentation since it is in pdf format and normally
# not used unless user wants it.
.if !defined(WITH_DOCUMENTATION)
NOPORTDOCS=	yes
.endif

# If WITH_DRAC variable present in the environment, qpopper builds
# with Dynamic Relay Authorization Control support.
.if defined(WITH_DRAC)
CONFIGURE_ARGS+=	--with-drac
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

# If WITH_FULL_POPD_DEBUG variable present in the environment, qpopper builds
# with more verbose debugging. See also -d option to qpopper.
.if defined(WITH_FULL_POPD_DEBUG)
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
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-password::poppassd.c \
		${FILESDIR}/extra-patch-password::auth_user.c
EPOPPASSD=	""
.else
EPOPPASSD=	"@comment "
.endif

# If WITH_SHY_ENABLED variable present,  qpopper does not present
# its version number within the POP3 session.
.if defined(WITH_SHY_ENABLED)
CONFIGURE_ARGS+=	--enable-shy
.endif

# If WITH STANDALONE_MODE variable present qpopper is built so it runs
# without inetd.
.if defined(WITH_STANDALONE_MODE)
CONFIGURE_ARGS+=	--enable-standalone
.endif

# The default is to build without SSL/TLS support.
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
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
		${PREFIX}/etc/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/GUIDE.pdf ${DOCSDIR}
.endif

post-install: install-conf-file
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

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
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
