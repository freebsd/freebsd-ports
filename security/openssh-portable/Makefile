# New ports collection makefile for: openssh
# Date created:  18 Mar 1999
# Whom:   dwcjr@inethouston.net
#
# $FreeBSD$
#

PORTNAME=	openssh
DISTVERSION=	5.2p1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	security ipv6
.if defined(OPENSSH_SNAPSHOT)
MASTER_SITES=	http://www.mindrot.org/openssh_snap/
.else
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenSSH/portable
.endif
PKGNAMESUFFIX=	${PORTABLE_SUFFIX}${GSSAPI_SUFFIX}${BASE_SUFFIX}
DISTNAME=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH

.if defined(OPENSSH_SNAPSHOT)
PORTREVISION!=		date -v-1d +%Y%m%d
NO_CHECKSUM=		yes
DISTNAME+=		${PORTNAME}-SNAP-${PORTREVISION}
.else
DISTNAME+=		${PORTNAME}-${DISTVERSION}
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN5=	moduli.5 ssh_config.5 sshd_config.5
MAN8=	sftp-server.8 sshd.8 ssh-keysign.8

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.*

USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-md5-passwords \
			--without-zlib-version-check --with-ssl-engine
PRECIOUS=		ssh_config sshd_config ssh_host_key ssh_host_key.pub \
			ssh_host_rsa_key ssh_host_rsa_key.pub ssh_host_dsa_key \
			ssh_host_dsa_key.pub
ETCOLD=			${PREFIX}/etc
PORTABLE_SUFFIX=	-portable

SUDO?=		# empty
MAKE_ENV+=	SUDO="${SUDO}"

OPTIONS=	PAM		"Enable pam(3) support"				on \
		TCP_WRAPPERS	"Enable tcp_wrappers support"			on \
		LIBEDIT		"Enable readline support to sftp(1)"		on \
		KERBEROS	"Enable kerberos (autodetection)"		on \
		SUID_SSH	"Enable suid SSH (Recommended off)"		off \
		BSM		"Enable OpenBSM Auditing"			off \
		GSSAPI		"Enable GSSAPI support (req: KERBEROS)"		off \
		KERB_GSSAPI	"Enable Kerberos/GSSAPI patch (req: GSSAPI)"	off \
		OPENSSH_CHROOT	"Enable CHROOT support"				off \
		HPN		"Enable HPN-SSH patch"				off \
		LPK		"Enable LDAP Public Key (LPK) patch"		off \
		X509		"Enable x509 certificate patch"			off \
		FILECONTROL	"Enable file control patch"			off \
		OVERWRITE_BASE	"OpenSSH overwrite base"			off

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.if defined(WITH_X509) && ( defined(WITH_HPN) || defined(WITH_LPK))
BROKEN=		X509 patch incompatible with HPN and LPK patches
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

.if !defined(WITHOUT_KERBEROS)
.if defined(KRB5_HOME) && exists(${KRB5_HOME}) || defined(WITH_GSSAPI)
.if defined(WITH_KERB_GSSAPI)
PATCH_DIST_STRIP=	-p0
PATCH_SITES+=		http://www.sxw.org.uk/computing/patches/
PATCHFILES+=		openssh-5.2p1-gsskex-all-20090726.patch
.endif
PORTABLE_SUFFIX=	# empty
GSSAPI_SUFFIX=		-gssapi
CONFLICTS+=		openssh-portable-*-[0-9]*
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5_HOME}
.if defined(HEIMDAL_HOME) && defined(KRB5_HOME) && ${HEIMDAL_HOME} == ${LOCALBASE}
LIB_DEPENDS+=		krb5.26:${PORTSDIR}/security/heimdal
.elif defined(KRB5_HOME) && defined(LOCALBASE) && ${KRB5_HOME} == ${LOCALBASE}
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.endif
.if ${OPENSSLBASE} == "/usr"
CONFIGURE_ARGS+=	--without-rpath
LDFLAGS=		# empty
.endif
.else
CONFLICTS+=		openssh-gssapi-*-[0-9]*
CONFIGURE_ARGS+=	--with-rpath=${OPENSSLRPATH}
.if exists(/usr/include/krb5.h)
CONFIGURE_ARGS+=	--with-kerberos5
EXTRA_PATCHES+=		${FILESDIR}/gss-serv.c.patch
.endif
.endif
.endif

.if ${OPENSSLBASE} != "/usr"
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLBASE}
.endif

.if defined(WITH_OPENSSH_CHROOT)
CFLAGS+=		-DCHROOT
.endif

.if defined(WITH_HPN)
EXTRA_PATCHES+=	${FILESDIR}/openssh-5.2p1-hpn13v6.diff
.endif

# See http://dev.inversepath.com/trac/openssh-lpk
.if defined(WITH_LPK)
EXTRA_PATCHES+=		${FILESDIR}/contrib-openssh-lpk-5.1p1-0.3.10.patch
USE_OPENLDAP=		yes
CPPFLAGS+=		-I${LOCALBASE}/include -DWITH_LDAP_PUBKEY
CONFIGURE_ARGS+=	--with-libs='-lldap' --with-ldflags='-L${LOCALBASE}/lib' \
			--with-cppflags='-I${LOCALBASE}/include -DWITH_LDAP_PUBKEY'
.endif

# resolve some patches incompatibility between LPK and HPN patches

.if defined(WITH_HPN) && defined(WITH_LPK)
EXTRA_PATCHES+=		${FILESDIR}/lpk+hpn-servconf.c.patch
.elif defined(WITH_HPN) && !defined(WITH_LPK)
EXTRA_PATCHES+=		${FILESDIR}/openssh-5.2p1-hpn13v6-servconf.c.diff
.elif defined(WITH_LPK) && !defined(WITH_HPN)
EXTRA_PATCHES+=		${FILESDIR}/contrib-openssh-lpk-5.1p1-0.3.10-servconf.c.patch
.endif

.if defined(WITH_LPK) && ${ARCH} == "amd64"
EXTRA_PATCHES+=		${FILESDIR}/contrib-openssh-5.1_p1-lpk-64bit.patch
.endif

# See http://www.roumenpetrov.info/openssh/
.if defined(WITH_X509)
PATCH_DIST_STRIP=	-p1
PATCH_SITES+=		http://www.roumenpetrov.info/openssh/x509-6.2/
PATCHFILES+=		openssh-5.2p1+x509-6.2.diff.gz
PLIST_SUB+=		X509=""
.else
PLIST_SUB+=		X509="@comment "
.endif

# See http://sftpfilecontrol.sourceforge.net/
.if defined(WITH_FILECONTROL)
EXTRA_PATCHES+=		${FILESDIR}/openssh-${DISTVERSION}.sftpfilecontrol-v1.3.patch
.endif

.if defined(WITH_OVERWRITE_BASE)
WITH_OPENSSL_BASE=	yes
BASE_SUFFIX=		-overwrite-base
CONFIGURE_ARGS+=	--localstatedir=/var
EMPTYDIR=		/var/empty
PREFIX=			/usr
ETCSSH=			/etc/ssh
USE_RC_SUBR=	yes
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

post-extract:
.if defined(OPENSSH_SNAPSHOT)
	@# rc.d script have same name of openssh snapshot dir
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-${DISTVERSION}
.endif

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
