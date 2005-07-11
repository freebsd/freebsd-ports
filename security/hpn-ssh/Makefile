# New ports collection makefile for: openssh
# Date created:  18 Mar 1999
# Whom:   dwcjr@inethouston.net
#
# $FreeBSD$
#

PORTNAME=	hpn-ssh
PORTVERSION=	3.9.0.1.${HPNVERSION}
PORTEPOCH=	1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/portable/%SUBDIR%/ \
		ftp://carroll.cac.psu.edu/pub/OpenBSD/OpenSSH/portable/%SUBDIR%/
PKGNAMESUFFIX?=	${GSSAPI_SUFFIX}${BASE_SUFFIX}
DISTNAME=	openssh-${OPENSSHVERSION}

PATCHFILES+=	openssh-${OPENSSHVERSION}-hpn${HPNVERSION}.diff
.if defined(WITH_NONE_CIPHER)
PATCHFILES+=	openssh-${OPENSSHVERSION}-hpn${HPNVERSION}-none.diff
.endif
PATCH_SITES=	http://www.psc.edu/networking/projects/hpn-ssh/
PATCH_DIST_STRIP=-p1

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	High Performance Enabled SSH/SCP

HPNVERSION=	11
OPENSSHVERSION=	3.9p1
WRKSRC=		${WRKDIR}/openssh-${OPENSSHVERSION}

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN5=	ssh_config.5 sshd_config.5
MAN8=	sftp-server.8 sshd.8 ssh-keysign.8

CONFLICTS?=	openssh-3.* ssh-1.* ssh2-3.*
USE_OPENSSL=	yes
CRYPTOLIBS=	-L${OPENSSLLIB} -lcrypto
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-md5-passwords
PRECIOUS=	ssh_config sshd_config \
		ssh_host_key ssh_host_key.pub \
		ssh_host_rsa_key ssh_host_rsa_key.pub \
		ssh_host_dsa_key ssh_host_dsa_key.pub
ETCOLD=		${PREFIX}/etc

.if exists(/usr/include/security/pam_modules.h)
CONFIGURE_ARGS+=	--with-pam
.endif

.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if !defined(ENABLE_SUID_SSH)
CONFIGURE_ARGS+=	--disable-suid-ssh
.endif

CONFLICTS+=	openssh-*

.if defined(KRB5_HOME) && exists(${KRB5_HOME}) || defined(WITH_GSSAPI)
GSSAPI_SUFFIX=	-gssapi
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5_HOME}
.else
.if !defined(WITHOUT_KERBEROS) && exists(/usr/include/krb5.h)
CONFIGURE_ARGS+=	--with-kerberos5
EXTRA_PATCHES+=		${FILESDIR}/gss-serv.c.patch
.endif
.endif

.if defined(BATCH)
EXTRA_PATCHES+=		${FILESDIR}/batch.patch
.endif

.if defined(WITH_OPENSSH_CHROOT)
CFLAGS+=		-DCHROOT
.endif

.if defined(OPENSSH_OVERWRITE_BASE)
WITH_OPENSSL_BASE=	yes
BASE_SUFFIX=	-overwrite-base
PREFIX=		/usr
MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man --localstatedir=/var
EMPTYDIR=	/var/empty
ETCSSH=		/etc/ssh
PLIST_SUB+=	NOTBASE="@comment "
PLIST_SUB+=	BASE=""
PKGMESSAGE=	pkg-message.empty
.else
.if exists(/var/empty)
EMPTYDIR=	/var/empty
.else
EMPTYDIR=	${PREFIX}/empty
.endif
ETCSSH=		${PREFIX}/etc/ssh
PLIST_SUB+=	NOTBASE=""
PLIST_SUB+=	BASE="@comment "
.endif
PLIST_SUB+=	EMPTYDIR=${EMPTYDIR}
CONFIGURE_ARGS+=	--sysconfdir=${ETCSSH}
CONFIGURE_ARGS+=	--with-privsep-path=${EMPTYDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure

post-configure:
	${SED} -e 's:__PREFIX__:${PREFIX}:g' \
		${FILESDIR}/sshd.sh > ${WRKSRC}/sshd.sh

pre-install:
.if defined(OPENSSH_OVERWRITE_BASE)
	-${MKDIR} ${EMPTYDIR}
.else
	-${MKDIR} ${PREFIX}/empty
.endif
	if ! pw groupshow sshd; then pw groupadd sshd -g 22; fi
	if ! pw usershow sshd; then pw useradd sshd -g sshd -u 22 \
		-h - -d ${EMPTYDIR} -s /nonexistent -c "sshd privilege separation"; fi
	-@[ ! -d ${ETCSSH} ] && ${MKDIR} ${ETCSSH}
.for i in ${PRECIOUS}
	-@[ -f ${ETCOLD}/${i} ] && [ ! -f ${ETCSSH}/${i} ] && \
		${ECHO_MSG} ">> Linking ${ETCSSH}/${i} from old layout." && \
		${LN} ${ETCOLD}/${i} ${ETCSSH}/${i}
.endfor

post-install:
.if !defined(OPENSSH_OVERWRITE_BASE)
	${INSTALL_SCRIPT} ${WRKSRC}/sshd.sh ${PREFIX}/etc/rc.d/sshd.sh.sample
.endif
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config.out ${ETCSSH}/ssh_config-dist
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config.out ${ETCSSH}/sshd_config-dist
.if !defined(OPENSSH_OVERWRITE_BASE)
	@${CAT} ${PKGMESSAGE}
.endif

test:
	(cd ${WRKSRC}/regress && ${SETENV} ${MAKE_ENV} \
	TEST_SHELL=/bin/sh \
	PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} )

.include <bsd.port.pre.mk>

SUDO?=
MAKE_ENV+=	SUDO="${SUDO}"

.if defined(KRB5_HOME) && exists(${KRB5_HOME}) || defined(WITH_GSSAPI)
.if ${OPENSSLBASE} == "/usr"
CONFIGURE_ARGS+=	--without-rpath
LDFLAGS=
.endif
.else
CONFIGURE_ARGS+=	--with-rpath=${OPENSSLRPATH}
.endif
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLBASE}

.include <bsd.port.post.mk>
