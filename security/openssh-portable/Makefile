# Created by: dwcjr@inethouston.net
# $FreeBSD$

PORTNAME=	openssh
DISTVERSION=	5.8p2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenSSH/portable
PKGNAMESUFFIX=	-portable

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN5=	moduli.5 ssh_config.5 sshd_config.5
MAN8=	sftp-server.8 sshd.8 ssh-keysign.8 ssh-pkcs11-helper.8

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.*

USE_PERL5_BUILD=	yes
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-md5-passwords \
			--without-zlib-version-check --with-ssl-engine
PRECIOUS=		ssh_config sshd_config ssh_host_key ssh_host_key.pub \
			ssh_host_rsa_key ssh_host_rsa_key.pub ssh_host_dsa_key \
			ssh_host_dsa_key.pub
ETCOLD=			${PREFIX}/etc

SUDO?=		# empty
MAKE_ENV+=	SUDO="${SUDO}"

OPTIONS_DEFINE=		PAM TCP_WRAPPERS LIBEDIT SUID_SSH BSM KERBEROS \
			KERB_GSSAPI OPENSSH_CHROOT HPN LPK X509 FILECONTROL \
			OVERWRITE_BASE
OPTIONS_DEFAULT=	LIBEDIT PAM TCP_WRAPPERS
TCP_WRAPPERS_DESC=	Enable tcp_wrappers support
SUID_SSH_DESC=		Enable suid SSH (Recommended off)
BSM_DESC=		Enable OpenBSM Auditing
KERB_GSSAPI_DESC=	Enable Kerberos/GSSAPI patch (req: GSSAPI)
OPENSSH_CHROOT_DESC=	Enable CHROOT support
HPN_DESC=		Enable HPN-SSH patch
LPK_DESC=		Enable LDAP Public Key (LPK) patch
X509_DESC=		Enable x509 certificate patch
FILECONTROL_DESC=	Enable file control patch (broken)
OVERWRITE_BASE_DESC=	OpenSSH overwrite base

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
.endif

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog
.endif

.if ${PORT_OPTIONS:MX509} && ${PORT_OPTIONS:MHPN}
BROKEN=		X509 patches and HPN patches do not apply cleanly together
.endif

.if ${PORT_OPTIONS:MX509} && ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		X509 patch incompatible with KERB_GSSAPI patch
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

.if !${PORT_OPTIONS:MSUID_SSH}
CONFIGURE_ARGS+=	--disable-suid-ssh
.endif

.if ${PORT_OPTIONS:MBSM}
CONFIGURE_ARGS+=	--with-audit=bsm
.endif

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-kerberos5
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.if ${PORT_OPTIONS:MKERB_GSSAPI}
PATCH_SITES+=		http://www.sxw.org.uk/computing/patches/
PATCHFILES+=		openssh-5.7p1-gsskex-all-20110125.patch
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

.if ${PORT_OPTIONS:MOPENSSH_CHROOT}
CFLAGS+=		-DCHROOT
.endif

.if ${PORT_OPTIONS:MHPN}
PATCH_SITES+=		http://mirror.shatow.net/freebsd/${PORTNAME}/
PATCHFILES+=		${PORTNAME}-5.8p1-hpn13v11.diff.gz
PATCH_DIST_STRIP=
.endif

# See http://code.google.com/p/openssh-lpk/wiki/Main
# and svn repo described here:
# http://code.google.com/p/openssh-lpk/source/checkout
.if ${PORT_OPTIONS:MLPK}
EXTRA_PATCHES+=		${FILESDIR}/openssh-lpk-5.8p2.patch
USE_OPENLDAP=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-ldap=yes \
			--with-libs='-lldap' \
			--with-ldflags='-L${LOCALBASE}/lib' \
			--with-cppflags='${CPPFLAGS}'
.endif

# See http://www.roumenpetrov.info/openssh/
.if ${PORT_OPTIONS:MX509}
PATCH_SITES+=		http://www.roumenpetrov.info/openssh/x509-7.0/
PATCHFILES+=		${PORTNAME}-5.8p1+x509-7.0.diff.gz
PATCH_DIST_STRIP=	-p1
PLIST_SUB+=		X509=""
MAN5+=			ssh_engine.5
.else
PLIST_SUB+=		X509="@comment "
.endif

# See http://sftpfilecontrol.sourceforge.net/
.if ${PORT_OPTIONS:MFILECONTROL}
# Latest sftpfilecontrol patch is against 5.4p1 which does not apply
# cleanly against 5.8p2, but it's close.
BROKEN=			latest upstream sftp file control public key patch is not up to date for OpenSSH 5.8p2
EXTRA_PATCHES+=		${FILESDIR}/openssh-${DISTVERSION}.sftpfilecontrol-v1.3.patch
.endif

.if ${PORT_OPTIONS:MOVERWRITE_BASE}
WITH_OPENSSL_BASE=	yes
CONFIGURE_ARGS+=	--localstatedir=/var
EMPTYDIR=		/var/empty
PREFIX=			/usr
ETCSSH=			/etc/ssh
USE_RCORDER=		openssh
PLIST_SUB+=		NOTBASE="@comment "
PLIST_SUB+=		BASE=""
PLIST_SUB+=		BASEPREFIX="${PREFIX}"
PLIST_SUB+=		ERASEEMPTY="@comment "
.else
.if exists(/var/empty)
EMPTYDIR=		/var/empty
PLIST_SUB+=		ERASEEMPTY="@comment "
.else
EMPTYDIR=		${PREFIX}/empty
PLIST_SUB+=		ERASEEMPTY=""
.endif
ETCSSH=			${PREFIX}/etc/ssh
USE_RC_SUBR=		openssh
PLIST_SUB+=		NOTBASE=""
PLIST_SUB+=		BASE="@comment "
.endif

# After all
SUB_LIST+=		ETCSSH="${ETCSSH}"
PLIST_SUB+=		EMPTYDIR="${EMPTYDIR}"
CONFIGURE_ARGS+=	--sysconfdir=${ETCSSH} --with-privsep-path=${EMPTYDIR}

RC_SCRIPT_NAME=		openssh

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure
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
	@${MKDIR} ${EMPTYDIR}
	if ! pw groupshow sshd; then pw groupadd sshd -g 22; fi
	if ! pw usershow sshd; then pw useradd sshd -g sshd -u 22 \
		-h - -d ${EMPTYDIR} -s /nonexistent -c "sshd privilege separation"; fi
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
	(cd ${WRKSRC}/regress && ${SETENV} ${MAKE_ENV} TEST_SHELL=/bin/sh \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

.include <bsd.port.post.mk>
