# Created by: pst
# $FreeBSD$

PORTNAME=	qpopper
PORTVERSION=	4.1.0
PORTREVISION=	6
CATEGORIES=	mail ipv6
MASTER_SITES=	http://core.ring.gr.jp/archives/net/mail/qpopper/ \
		http://ftp.osuosl.org/.1/blfs/7.7/q/ \
		LOCAL/eugen
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Berkeley POP 3 server (now maintained by Qualcomm)

# BSD-style license
LICENSE=	QUALCOMM
LICENSE_NAME=	Qualcomm BSD-style license
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:features

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OS_DEFS="-DSETPROCTITLE ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-nonauth-file=${POPUSERS_FILE} \
		--without-gdbm ac_cv_header_gdbm_h=no \
		--enable-keep-temp-drop
LIBS+=		-L${LOCALBASE}/lib -lcrypt -lmd -lutil

PLIST_SUB=	EPOPPASSD=${EPOPPASSD} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		POP_MODE_DIR=${POP_MODE_DIR} \
		POP_MODE_CONF=${POP_MODE_CONF} \
		QPOPAUTH=${QPOPAUTH}

SUB_FILES=	pkg-message

# internal configuration
USERS?=		pop
GROUPS?=	daemon
POP_MODE_DIR=	0711
POP_MODE_CONF=	0444
POPUSERS_FILE=	${ETCDIR}/popusers
SAMPLE_EXT=	.sample

PKGDEINSTALL=	${PKGINSTALL}

OPTIONS_DEFINE=	APOP_ONLY APOP DOCUMENTATION DRAC FULL_POPD_DEBUG PAM \
	POPPASSD SAMPLE_POPUSERS SHY_ENABLED \
	OPENSSL STANDALONE_MODE U_OPTION

APOP_ONLY_DESC=	build with APOP authentication only
APOP_DESC=	build with APOP
DOCUMENTATION_DESC=	install pdf documentation
DRAC_DESC=	build with Dynamic Relay Authorization
FULL_POPD_DEBUG_DESC=	build with more verbose debugging
PAM_DESC=	build with PAM authentication
POPPASSD_DESC=	build the poppassd daemon
SAMPLE_POPUSERS_DESC=	build a default reject file
SHY_ENABLED_DESC=	hide qpopper version in POP3 banner
STANDALONE_MODE_DESC=	build qpopper to be run without inetd
U_OPTION_DESC=	include support for user .qpopper-options

OPTIONS_DEFAULT=	APOP OPENSSL U_OPTION
OPTIONS_SUB=	yes

OPENSSL_USES=	ssl

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MAPOP)
QPOPAUTH=	"@comment "
.else
CONFIGURE_ARGS+=	--enable-apop=${ETCDIR}/pop.auth \
			--with-popuid=${USERS}
QPOPAUTH=	""
# If WITH_APOP_ONLY variable present in the environment, qpopper builds
# with APOP authentication only.
.if ${PORT_OPTIONS:MAPOP_ONLY}
OS_DEFS+=	-DAPOP_ONLY
.endif
.endif

# If WITH_DRAC variable present in the environment, qpopper builds
# with Dynamic Relay Authorization Control support.
.if ${PORT_OPTIONS:MDRAC}
CONFIGURE_ARGS+=	--with-drac
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:mail/drac
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
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-password__poppassd.c \
		${FILESDIR}/extra-patch-password__auth_user.c
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
USE_RC_SUBR=	${PORTNAME}
.endif

# The default is to build without SSL/TLS support.
.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

# openssl-1.1.1 no longer has SSLv2 support
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085
CFLAGS+=		-DOPENSSL_NO_SSL2
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}"
.endif

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|-freg-struct-return||' ${WRKSRC}/configure
.endif
	@${RM} ${WRKSRC}/popper/md5.h
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/man/*
	@${REINPLACE_CMD} -e \
		's|\$${sbindir}/sendmail|${LOCALBASE}/sbin/sendmail|g' \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MPOPPASSD}
	@${REINPLACE_CMD} -e 's|/usr/bin/smbpasswd|${LOCALBASE}/bin/smbpasswd|' \
		${WRKSRC}/password/poppassd.c
.endif
.if empty(PORT_OPTIONS:MU_OPTION)
	@${REINPLACE_CMD} -E -e 's|(getopt \(.+)u|\1|' \
		${WRKSRC}/popper/main.c
.endif

do-install:
.if ${PORT_OPTIONS:MAPOP}
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${STAGEDIR}${PREFIX}/bin/qpopauth
	${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${STAGEDIR}${PREFIX}/man/man8/qpopauth.8
	${LN} -sf qpopauth ${STAGEDIR}${PREFIX}/bin/qapopauth
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${STAGEDIR}${PREFIX}/libexec/qpopper
	${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${STAGEDIR}${PREFIX}/man/man8/qpopper.8
.if ${PORT_OPTIONS:MPOPPASSD}
	${INSTALL_PROGRAM} ${WRKSRC}/password/poppassd ${STAGEDIR}${PREFIX}/libexec/qpoppassd
.endif
.if ${PORT_OPTIONS:MDOCUMENTATION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/GUIDE.pdf ${STAGEDIR}${DOCSDIR}
.endif

# based on original from op port, written by Cyrille Lefevre
# <clefevre@citeweb.net>.
	@if [ ! -f ${CONF_DIR}/${CONF_FILE}${SAMP_SUFX} ]; then \
		${MKDIR} ${STAGEDIR}${ETCDIR} ; \
		if [ -f /etc/ftpusers ] && [ -n "${PORT_OPTIONS:MSAMPLE_POPUSERS}" ]; then \
			${INSTALL} -c /etc/ftpusers ${STAGEDIR}${POPUSERS_FILE}${SAMPLE_EXT} ; \
		else \
			${CP} /dev/null ${STAGEDIR}${POPUSERS_FILE}${SAMPLE_EXT} ; \
		fi ; \
	fi

.include <bsd.port.post.mk>
