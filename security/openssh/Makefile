# New ports collection makefile for:	OpenSSH
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

PORTNAME=	openssh
PORTVERSION=	3.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp.usa.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp1.se.openbsd.org/pub/OpenBSD/OpenSSH/
DISTNAME=	openssh-${PORTVERSION}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	openbsd28_${PORTVERSION}.patch

MAINTAINER=	dinoex@FreeBSD.org

MAN1=		scp.1 slogin.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh.1 \
		ssh-keyscan.1 sftp.1
MAN5=		ssh_config.5 sshd_config.5
MAN8=		sshd.8 sftp-server.8 ssh-keysign.8
MANCOMPRESSED=	yes
MODIFY=		ssh.h sshd_config sshd.sh pathnames.h
FIXME=		lib/Makefile scp/Makefile sftp/Makefile sftp-server/Makefile \
		ssh/Makefile ssh-add/Makefile ssh-agent/Makefile \
		ssh-keygen/Makefile ssh-keyscan/Makefile sshd/Makefile

.include <bsd.port.pre.mk>

.include <${PORTSDIR}/security/openssl/Makefile.ssl>

CRYPTOLIBS=	-L${OPENSSLLIB} -lcrypto
# Here, MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV+=	DESTDIR=${PREFIX} MANDIR=/man/man CRYPTOLIBS="${CRYPTOLIBS}"
.if ${OSVERSION} < 400014
MAKE_ENV+=	COMPAT_GETADDRINFO=yes
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
MAKE_ENV+=	SKEY=yes
.endif
WRKSRC=		${WRKDIR}/ssh

post-extract:
	@${CP} ${FILESDIR}/strlcat.c ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/
	@${CP} ${FILESDIR}/sshd.sh ${WRKSRC}/
.if ${OSVERSION} < 400014
	@${CP} ${FILESDIR}/getaddrinfo.c  ${FILESDIR}/name6.c ${WRKSRC}/lib/
	@${CP} ${FILESDIR}/bindresvport.c ${FILESDIR}/rcmd.c ${WRKSRC}/lib/
	@${CP} ${FILESDIR}/getnameinfo.c ${WRKSRC}/lib/
	@${CP} ${FILESDIR}/netdb.h ${WRKSRC}/
.endif

post-patch:
	@${MV} ${WRKSRC}/sshd_config ${WRKSRC}/sshd_config.sed
	${SED} -e "s=/etc/ssh=${PREFIX}/etc/ssh=" \
		-e "s=/usr/libex=${PREFIX}/libex=" \
		${WRKSRC}/sshd_config.sed > ${WRKSRC}/sshd_config
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor
	@${PERL5} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h	\
		${WRKSRC}/sshd_config ${WRKSRC}/sshd.sh \
		${WRKSRC}/pathnames.h

.if ${OSVERSION} < 430000
post-configure:
.for i in ${FIXME}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s=KERBEROS[:]L=KERBEROS=" \
		-e "s=KERBEROS5[:]L=KERBEROS5=" \
		-e "s=AFS[:]L=AFS=" \
		-e "s=TCP_WRAPPERS[:]L=TCP_WRAPPERS=" \
		-e "s=SKEY[:]L=SKEY=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor
.endif

pre-install:
	${MKDIR} ${PREFIX}/libdata/ssh

post-install:
.if !defined(BATCH)
.if !exists(${PREFIX}/etc/ssh_host_key)
	@${ECHO_MSG} ">> Generating an RSA1 secret host key."
	${PREFIX}/bin/ssh-keygen -t rsa1 -N "" -f ${PREFIX}/etc/ssh_host_key
.endif
.if !exists(${PREFIX}/etc/ssh_host_rsa_key)
	@${ECHO_MSG} ">> Generating a RSA secret host key."
	${PREFIX}/bin/ssh-keygen -t rsa -N "" -f ${PREFIX}/etc/ssh_host_rsa_key
.endif
.if !exists(${PREFIX}/etc/ssh_host_dsa_key)
	@${ECHO_MSG} ">> Generating a DSA secret host key."
	${PREFIX}/bin/ssh-keygen -t dsa -N "" -f ${PREFIX}/etc/ssh_host_dsa_key
.endif
.endif
.if !exists(${PREFIX}/etc/moduli)
	@${ECHO_MSG} ">> Installing moduli."
	${INSTALL_DATA} -c ${FILESDIR}/moduli ${PREFIX}/etc/moduli
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/sshd.sh ${PREFIX}/etc/rc.d/sshd.sh.sample
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config ${PREFIX}/etc/ssh_config-dist
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config ${PREFIX}/etc/sshd_config-dist
.if !exists(${PREFIX}/etc/ssh_config) && !exists(${PREFIX}/etc/sshd_config)
	${INSTALL_DATA} -c ${WRKSRC}/ssh_config ${PREFIX}/etc/ssh_config
	${INSTALL_DATA} -c ${WRKSRC}/sshd_config ${PREFIX}/etc/sshd_config
.else
	@${ECHO_MSG} ">> ${PREFIX}/etc/ssh{,d}_config exists, not being replaced!"
	@${ECHO_MSG} ">> If this is left over from another version of SSH, you will"
	@${ECHO_MSG} ">> need to update it to work with OpenSSH."
.endif

.include <bsd.port.post.mk>
