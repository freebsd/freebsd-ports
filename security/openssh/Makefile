# New ports collection makefile for:	OpenSSH
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

PORTNAME=	openssh
PORTVERSION=	3.6.1
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp.usa.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp1.se.openbsd.org/pub/OpenBSD/OpenSSH/
PKGNAMESUFFIX?=	${SKEY_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	openssh-${PORTVERSION}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	openbsd28_${PORTVERSION}.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenBSD's secure shell client and server (remote login program)

CONFLICTS?=	openssh-portable-* openssh-gssapi-* ssh-1.* ssh2-3.*
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/ssh

MAN1=		scp.1 slogin.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh.1 \
		ssh-keyscan.1 sftp.1
MAN5=		ssh_config.5 sshd_config.5
MAN8=		sshd.8 sftp-server.8 ssh-keysign.8
MANCOMPRESSED=	yes

MODIFY=		ssh.h sshd_config sshd.sh pathnames.h
FIXME=		lib/Makefile scp/Makefile sftp/Makefile sftp-server/Makefile \
		ssh/Makefile ssh-add/Makefile ssh-agent/Makefile \
		ssh-keygen/Makefile ssh-keyscan/Makefile sshd/Makefile
ADDME+=		auth-pam.c auth-pam.h auth2-pam.c
ADDLIB+=	strlcat.c strlcpy.c \
		getaddrinfo.c name6.c bindresvport.c rcmd.c getnameinfo.c
PRECIOUS=	ssh_config sshd_config \
		ssh_host_key ssh_host_key.pub \
		ssh_host_rsa_key ssh_host_rsa_key.pub \
		ssh_host_dsa_key ssh_host_dsa_key.pub
# PAM ist broken, use openssh-portable instead.
PAM=no

.include <bsd.port.pre.mk>

CRYPTOLIBS=	-L${OPENSSLLIB} -lcrypto
# Here, MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV+=	DESTDIR=${PREFIX} MANDIR=/man/man CRYPTOLIBS="${CRYPTOLIBS}"

.if ${OSVERSION} < 400014
MAKE_ENV+=	COMPAT_GETADDRINFO=yes
ADDME+=		netdb.h
.else
MAKE_ENV+=	INET6FLAGS=-DINET6
.endif

.if !exists(/usr/include/tcpd.h)
MAKE_ENV+=	TCP_WRAPPERS=no
.endif

.if defined(AFS) && ${AFS} == YES
MAKE_ENV+=	AFS=yes
.endif

.if defined(KERBEROS) && ${KERBEROS} == YES
MAKE_ENV+=	KERBEROS=yes
.endif

.if exists(/usr/include/security/pam_modules.h)
PAM?=		yes
.else
PAM=		no
.endif
MAKE_ENV+=	PAM=${PAM}

.if defined(SKEY) && ${SKEY} == YES
SKEY_SUFFIX=	-skey
MAKE_ENV+=	SKEY=yes
.endif

EMPTYDIR=	${PREFIX}/empty
ETCOLD=		${PREFIX}/etc
ETCSSH=		${PREFIX}/etc/ssh
PLIST_SUB+=	EMPTYDIR=${EMPTYDIR}

post-extract:
	@${CP} ${FILESDIR}/sshd.sh ${WRKSRC}/
.for i in ${ADDLIB}
	@${CP} ${FILESDIR}/${i} ${WRKSRC}/lib/
.endfor
.for i in ${ADDME}
	@${CP} ${FILESDIR}/${i} ${WRKSRC}/
.endfor

pre-configure:
.for i in ${MODIFY:S/pathnames.h//} ${MAN1:S/slogin.1//} ${MAN5} ${MAN8}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s=/etc/ssh=${ETCSSH}/ssh=" \
		-e "s=/usr/libex=${PREFIX}/libex=" \
		-e 's:__PREFIX__:${PREFIX}:g' \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor
.for i in pathnames.h
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e 's:__PREFIX__:${PREFIX}:g' \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor

.if ${OSVERSION} < 430000
post-configure:
.for i in ${FIXME}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s=KERBEROS[:]L=KERBEROS=" \
		-e "s=KERBEROS5[:]L=KERBEROS5=" \
		-e "s=AFS[:]L=AFS=" \
		-e "s=TCP_WRAPPERS[:]L=TCP_WRAPPERS=" \
		-e "s=SKEY[:]L=SKEY=" \
		-e "s=PAM[:]L=PAM=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor
.endif

pre-install:
	-${MKDIR} ${EMPTYDIR}
	if ! pw groupshow sshd; then pw groupadd sshd -g 22; fi
	if ! pw usershow sshd; then pw useradd sshd -g sshd -u 22 \
		-h - -d ${EMPTYDIR} -s /nonexistent -c "sshd privilege separation"; fi
	${MKDIR} ${PREFIX}/libdata/ssh
	-@[ ! -d ${ETCSSH} ] && ${MKDIR} ${ETCSSH}
.for i in ${PRECIOUS}
	-@[ -f ${ETCOLD}/${i} ] && [ ! -f ${ETCSSH}/${i} ] && \
		${ECHO_MSG} ">> Linking ${ETCSSH}/${i} from old layout." && \
		${LN} ${ETCOLD}/${i} ${ETCSSH}/${i}
.endfor

post-install:
.if !defined(BATCH)
.if !exists(${ETCSSH}/ssh_host_key) && !exists(${ETCOLD}/ssh_host_key)
	@${ECHO_MSG} ">> Generating an RSA1 secret host key."
	${PREFIX}/bin/ssh-keygen -t rsa1 -N "" -f ${ETCSSH}/ssh_host_key
.endif
.if !exists(${ETCSSH}/ssh_host_rsa_key) && !exists(${ETCOLD}/ssh_host_rsa_key)
	@${ECHO_MSG} ">> Generating a RSA secret host key."
	${PREFIX}/bin/ssh-keygen -t rsa -N "" -f ${ETCSSH}/ssh_host_rsa_key
.endif
.if !exists(${ETCSSH}/ssh_host_dsa_key) && !exists(${ETCOLD}/ssh_host_dsa_key)
	@${ECHO_MSG} ">> Generating a DSA secret host key."
	${PREFIX}/bin/ssh-keygen -t dsa -N "" -f ${ETCSSH}/ssh_host_dsa_key
.endif
.endif
.if !exists(${ETCSSH}/moduli)
	@${ECHO_MSG} ">> Installing moduli."
	${INSTALL_DATA} -c ${FILESDIR}/moduli ${ETCSSH}/moduli
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/sshd.sh ${PREFIX}/etc/rc.d/sshd.sh.sample
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config ${ETCSSH}/ssh_config-dist
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config ${ETCSSH}/sshd_config-dist
.if !exists(${ETCSSH}/ssh_config) && !exists(${ETCSSH}/sshd_config) \
	&& !exists(${ETCOLD}/ssh_config) && !exists(${ETCOLD}/sshd_config)
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config ${ETCSSH}/ssh_config
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config ${ETCSSH}/sshd_config
.else
	@${ECHO_MSG} ">> ${ETCSSH}/ssh{,d}_config exists, not being replaced!"
	@${ECHO_MSG} ">> If this is left over from another version of SSH, you will"
	@${ECHO_MSG} ">> need to update it to work with OpenSSH."
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
