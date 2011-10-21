# New ports collection makefile for: openssh
# Date created:  18 Mar 1999
# Whom:   dwcjr@inethouston.net
#
# $FreeBSD$
#

PORTNAME=	openssh
DISTVERSION=	5.8p2
PORTEPOCH=	1
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenSSH/portable
PKGNAMESUFFIX=	-portable

MAINTAINER=	magik@roorback.net
COMMENT=	The portable version of OpenBSD's OpenSSH

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN5=	moduli.5 ssh_config.5 sshd_config.5
MAN8=	sftp-server.8 sshd.8 ssh-keysign.8 ssh-pkcs11-helper.8

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.*

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

OPTIONS=	PAM		"Enable pam(3) support"				on \
		TCP_WRAPPERS	"Enable tcp_wrappers support"			on \
		LIBEDIT		"Enable readline support to sftp(1)"		on \
		SUID_SSH	"Enable suid SSH (Recommended off)"		off \
		BSM		"Enable OpenBSM Auditing"			off \
		KERBEROS	"Enable kerberos (autodetection)"		off \
		KERB_GSSAPI	"Enable Kerberos/GSSAPI patch (req: GSSAPI)"	off \
		OPENSSH_CHROOT	"Enable CHROOT support"				off \
		HPN		"Enable HPN-SSH patch"				off \
		LPK		"Enable LDAP Public Key (LPK) patch"		off \
		X509		"Enable x509 certificate patch"			off \
		FILECONTROL	"Enable file control patch (broken)"		off \
		OVERWRITE_BASE	"OpenSSH overwrite base"			off

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
.endif

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog
.endif

.if defined(WITH_X509) && defined(WITH_HPN)
BROKEN=		X509 patches and HPN patches do not apply cleanly together
.endif

.if defined(WITH_X509) && defined(WITH_KERB_GSSAPI)
BROKEN=		X509 patch incompatible with KERB_GSSAPI patch
.endif

.if defined(OPENSSH_OVERWRITE_BASE)
WITH_OVERWRITE_BASE=	yes
.endif

.if !defined(WITHOUT_PAM) && exists(/usr/include/security/pam_modules.h)
CONFIGURE_ARGS+=	--with-pam
.endif

.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if !defined(WITHOUT_LIBEDIT)
CONFIGURE_ARGS+=	--with-libedit
.endif

.if !defined(WITH_SUID_SSH)
CONFIGURE_ARGS+=	--disable-suid-ssh
.endif

.if defined(WITH_BSM)
CONFIGURE_ARGS+=	--with-audit=bsm
.endif

.if defined(WITH_KERBEROS)
CONFIGURE_ARGS+=	--with-kerberos5
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.if defined(WITH_KERB_GSSAPI)
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

.if defined(WITH_OPENSSH_CHROOT)
CFLAGS+=		-DCHROOT
.endif

.if defined(WITH_HPN)
PATCH_SITES+=		http://www.psc.edu/networking/projects/hpn-ssh/
PATCHFILES+=		${PORTNAME}-5.8p1-hpn13v11.diff.gz
PATCH_DIST_STRIP=
.endif

# See http://code.google.com/p/openssh-lpk/wiki/Main
# and svn repo described here:
# http://code.google.com/p/openssh-lpk/source/checkout
.if defined(WITH_LPK)
EXTRA_PATCHES+=		${FILESDIR}/openssh-lpk-5.8p2.patch
USE_OPENLDAP=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-ldap=yes \
			--with-libs='-lldap' \
			--with-ldflags='-L${LOCALBASE}/lib' \
			--with-cppflags='${CPPFLAGS}'
.endif

# See http://www.roumenpetrov.info/openssh/
.if defined(WITH_X509)
PATCH_SITES+=		http://www.roumenpetrov.info/openssh/x509-7.0/
PATCHFILES+=		${PORTNAME}-5.8p1+x509-7.0.diff.gz
PATCH_DIST_STRIP=	-p1
PLIST_SUB+=		X509=""
.else
PLIST_SUB+=		X509="@comment "
.endif

# See http://sftpfilecontrol.sourceforge.net/
.if defined(WITH_FILECONTROL)
# Latest sftpfilecontrol patch is against 5.4p1 which does not apply
# cleanly against 5.8p2, but it's close.
BROKEN=			latest upstream sftp file control public key patch is not up to date for OpenSSH 5.8p2
EXTRA_PATCHES+=		${FILESDIR}/openssh-${DISTVERSION}.sftpfilecontrol-v1.3.patch
.endif

.if defined(WITH_OVERWRITE_BASE)
WITH_OPENSSL_BASE=	yes
CONFIGURE_ARGS+=	--localstatedir=/var
EMPTYDIR=		/var/empty
PREFIX=			/usr
ETCSSH=			/etc/ssh
USE_RC_SUBR=		yes
SUB_FILES+=		openssh
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
.if defined(WITH_HPN)
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
.if defined(WITH_OVERWRITE_BASE)
	@${ECHO_CMD} "===> Installing rc.d startup script(s)"
	@${ECHO_CMD} "@cwd ${LOCALBASE}" >> ${TMPPLIST}
	@${MKDIR} ${LOCALBASE}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/openssh ${LOCALBASE}/etc/rc.d/${RC_SCRIPT_NAME}
	@${ECHO_CMD} "etc/rc.d/${RC_SCRIPT_NAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

test:	build
	(cd ${WRKSRC}/regress && ${SETENV} ${MAKE_ENV} TEST_SHELL=/bin/sh \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

.include <bsd.port.post.mk>
