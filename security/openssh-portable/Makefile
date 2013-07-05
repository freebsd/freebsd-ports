# Created by: dwcjr@inethouston.net
# $FreeBSD$

PORTNAME=	openssh
DISTVERSION=	6.2p2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenSSH/portable
PKGNAMESUFFIX=	-portable

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH

LICENSE=	BSD

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN5=	moduli.5 ssh_config.5 sshd_config.5
MAN8=	sftp-server.8 sshd.8 ssh-keysign.8 ssh-pkcs11-helper.8

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.*

# XXX: ports/52706 will allow using DEFAULT,x509 here.
PATCH_SITES+=		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
			http://mirror.shatow.net/freebsd/${PORTNAME}/:x509

USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=		autoconf autoheader
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		ac_cv_func_strnvis=no
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-md5-passwords \
			--without-zlib-version-check --with-ssl-engine
PRECIOUS=		ssh_config sshd_config ssh_host_key ssh_host_key.pub \
			ssh_host_rsa_key ssh_host_rsa_key.pub ssh_host_dsa_key \
			ssh_host_dsa_key.pub
ETCOLD=			${PREFIX}/etc

SUDO?=		# empty
MAKE_ENV+=	SUDO="${SUDO}"

OPTIONS_DEFINE=		PAM TCP_WRAPPERS LIBEDIT BSM \
			HPN LPK X509 KERB_GSSAPI \
			OVERWRITE_BASE SCTP AES_THREADED
OPTIONS_DEFAULT=	LIBEDIT PAM TCP_WRAPPERS HPN
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	MIT HEIMDAL HEIMDAL_BASE
TCP_WRAPPERS_DESC=	Enable tcp_wrappers support
BSM_DESC=		Enable OpenBSM Auditing
KERB_GSSAPI_DESC=	Enable Kerberos/GSSAPI patch (req: GSSAPI)
HPN_DESC=		Enable HPN-SSH patch
LPK_DESC=		Enable LDAP Public Key (LPK) [OBSOLETE]
X509_DESC=		Enable x509 certificate patch
SCTP_DESC=		Enable SCTP support
OVERWRITE_BASE_DESC=	OpenSSH overwrite base
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
MIT_DESC=		MIT Kerberos (security/krb5)
AES_THREADED_DESC=	Threaded AES-CTR [HPN/Experimental]

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
CONFIGURE_LIBS+=	-lutil
.endif

# 900007 is when utmp(5) was removed and utmpx(3) added
.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog
.else
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-sshd-utmp-size
.endif

.if ${PORT_OPTIONS:MX509}
.  if ${PORT_OPTIONS:MHPN}
BROKEN=		X509 patch and HPN patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MAES_THREADED}
BROKEN=		X509 patch and AES_THREADED patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MSCTP}
BROKEN=		X509 patch and SCTP patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MLPK}
BROKEN=		X509 patch and LPK patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		X509 patch incompatible with KERB_GSSAPI patch
.  endif

.endif

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		KERB_GSSAPI Requires either MIT or HEMIDAL, does not build with base Heimdal currently
.endif

.if defined(OPENSSH_OVERWRITE_BASE)
PORT_OPTIONS+=		OVERWRITE_BASE
.endif

.if ${PORT_OPTIONS:MPAM} && exists(/usr/include/security/pam_modules.h)
CONFIGURE_ARGS+=	--with-pam
.endif

.if ${PORT_OPTIONS:MTCP_WRAPPERS} && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if ${PORT_OPTIONS:MLIBEDIT}
CONFIGURE_ARGS+=	--with-libedit
.endif

.if ${PORT_OPTIONS:MBSM}
CONFIGURE_ARGS+=	--with-audit=bsm
.endif

.if ${PORT_OPTIONS:MMIT} || ${PORT_OPTIONS:MHEIMDAL} || ${PORT_OPTIONS:MHEIMDAL_BASE}
CONFIGURE_ARGS+=	--with-kerberos5
.  if ${PORT_OPTIONS:MMIT}
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.  elif ${PORT_OPTIONS:MHEIMDAL}
LIB_DEPENDS+=		krb5.26:${PORTSDIR}/security/heimdal
.  elif ${PORT_OPTIONS:MHEIMDAL_BASE}
.	if !exists(/usr/lib/libkrb5.so)
IGNORE=		You have selected HEIMDAL_BASE but do not have heimdal installed in base
.	else
CONFIGURE_LIBS+=	-lgssapi_krb5
.	endif
.  endif

# Adapated from 5.7 patch at http://www.sxw.org.uk/computing/patches/
.if ${PORT_OPTIONS:MKERB_GSSAPI}
PATCHFILES+=		openssh-6.2p2-gsskex-all-20110125.patch.gz
PATCH_DIST_STRIP=
.endif
.if ${OPENSSLBASE} == "/usr"
CONFIGURE_ARGS+=	--without-rpath
LDFLAGS=		# empty
.endif
.endif

.if ${OPENSSLBASE} != "/usr"
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLBASE}
.endif

# http://www.psc.edu/index.php/hpn-ssh
.if ${PORT_OPTIONS:MHPN}
HPN_VERSION=		13v14
PATCHFILES+=		${PORTNAME}-6.2p1-hpn${HPN_VERSION}.diff.gz
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-hpn-window-size
PATCH_DIST_STRIP=
.endif

# http://www.psc.edu/index.php/hpn-ssh
.if ${PORT_OPTIONS:MAES_THREADED}
AES_THREADED_VERSION=		v14
PATCHFILES+=		${PORTNAME}-6.2p1-CTR-threaded-${AES_THREADED_VERSION}.diff.gz
PATCH_DIST_STRIP=
.endif

# See http://code.google.com/p/openssh-lpk/wiki/Main
# and svn repo described here:
# http://code.google.com/p/openssh-lpk/source/checkout
# LPK is now OBSOLETE with 6.2: https://code.google.com/p/openssh-lpk/issues/detail?id=15#c1
.if ${PORT_OPTIONS:MLPK}
PATCHFILES+=		${PORTNAME}-lpk-6.2p1.patch.gz
USE_OPENLDAP=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-ldap=yes \
			--with-ldflags='-L${LOCALBASE}/lib' \
			--with-cppflags='${CPPFLAGS}'
CONFIGURE_LIBS+=	-lldap
.endif

# See http://www.roumenpetrov.info/openssh/
.if ${PORT_OPTIONS:MX509}
X509_VERSION=		7.4.1
PATCH_SITES+=		http://www.roumenpetrov.info/openssh/x509-${X509_VERSION}/:x509
PATCHFILES+=		${PORTNAME}-6.2p1+x509-${X509_VERSION}.diff.gz:x509
PATCH_DIST_STRIP=	-p1
PLIST_SUB+=		X509=""
MAN5+=			ssh_engine.5
.else
PLIST_SUB+=		X509="@comment "
.endif

# See https://bugzilla.mindrot.org/show_bug.cgi?id=2016
.if ${PORT_OPTIONS:MSCTP}
PATCHFILES+=		${PORTNAME}-sctp-2163.patch.gz
CONFIGURE_ARGS+=	--with-sctp
.endif

EMPTYDIR=		/var/empty

.if ${PORT_OPTIONS:MOVERWRITE_BASE}
WITH_OPENSSL_BASE=	yes
CONFIGURE_ARGS+=	--localstatedir=/var
PREFIX=			/usr
ETCSSH=			/etc/ssh
USE_RCORDER=		openssh
PLIST_SUB+=		NOTBASE="@comment "
PLIST_SUB+=		BASE=""
PLIST_SUB+=		BASEPREFIX="${PREFIX}"
.else
ETCSSH=			${PREFIX}/etc/ssh
USE_RC_SUBR=		openssh
PLIST_SUB+=		NOTBASE=""
PLIST_SUB+=		BASE="@comment "
.endif

# After all
SUB_LIST+=		ETCSSH="${ETCSSH}"
CONFIGURE_ARGS+=	--sysconfdir=${ETCSSH} --with-privsep-path=${EMPTYDIR}
.if !empty(CONFIGURE_LIBS)
CONFIGURE_ARGS+=	--with-libs='${CONFIGURE_LIBS}'
.endif

RC_SCRIPT_NAME=		openssh

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|install: \(.*\) host-key check-config|install: \1|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
			${WRKSRC}/pathnames.h ${WRKSRC}/sshd_config.5 \
			${WRKSRC}/ssh_config.5
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' \
		-e 's|%%RC_SCRIPT_NAME%%|${RC_SCRIPT_NAME}|' ${WRKSRC}/sshd.8
	@${REINPLACE_CMD} -E -e 's|SSH_VERSION|TMP_SSH_VERSION|' \
		-e 's|.*SSH_RELEASE.*||' ${WRKSRC}/version.h
	@${ECHO_CMD} '#define FREEBSD_PORT_VERSION	" FreeBSD-${PKGNAME}"' >> \
		${WRKSRC}/version.h
	@${ECHO_CMD} '#define SSH_VERSION	TMP_SSH_VERSION SSH_PORTABLE FREEBSD_PORT_VERSION' >> \
		${WRKSRC}/version.h
	@${ECHO_CMD} '#define SSH_RELEASE	TMP_SSH_VERSION SSH_PORTABLE FREEBSD_PORT_VERSION' >> \
		${WRKSRC}/version.h
.if ${PORT_OPTIONS:MHPN}
	@${REINPLACE_CMD} -e 's|TMP_SSH_VERSION SSH_PORTABLE|TMP_SSH_VERSION SSH_PORTABLE SSH_HPN|' \
		${WRKSRC}/version.h
.endif

pre-su-install:
.if !exists(${ETCSSH})
	@${MKDIR} ${ETCSSH}
.endif
.for i in ${PRECIOUS}
.if exists(${ETCOLD}/${i}) && !exists(${ETCSSH}/${i})
	@${ECHO_MSG} "==>   Linking ${ETCSSH}/${i} from old layout."
	${LN} ${ETCOLD}/${i} ${ETCSSH}/${i}
.endif
.endfor

post-install:
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config.out ${ETCSSH}/ssh_config-dist
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config.out ${ETCSSH}/sshd_config-dist

	@${CAT} ${PKGMESSAGE}

test:	build
	(cd ${WRKSRC}/regress && ${SETENV} OBJ=${WRKDIR} ${MAKE_ENV} TEST_SHELL=/bin/sh \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

.include <bsd.port.post.mk>
