# New ports collection makefile for:	OpenSSH
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

PORTNAME=	OpenSSH
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp.usa.openbsd.org/pub/OpenBSD/OpenSSH/ \
		ftp://ftp1.se.openbsd.org/pub/OpenBSD/OpenSSH/
DISTNAME=	openssh-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	YES

MAN1=		scp.1 slogin.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh.1
MAN8=		sshd.8
MANCOMPRESSED=	yes
 
.include <bsd.port.pre.mk>

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
	@${MKDIR} ${WRKSRC}/pam_ssh
	@${CP} ${FILESDIR}/pam_ssh_Makefile ${WRKSRC}/pam_ssh/Makefile
	@${CP} ${FILESDIR}/pam_ssh.c ${WRKSRC}/pam_ssh/

post-patch:
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h	\
		${WRKSRC}/sshd_config ${WRKSRC}/pam_ssh/pam_ssh.c	\
		${WRKSRC}/sshd.sh

.if ${PAM} == yes
PLIST=		${WRKDIR}/PLIST

do-configure:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
	@${ECHO} "@cwd /usr" >> ${PLIST}
	@${ECHO} "lib/pam_ssh.so" >> ${PLIST}
.endif

post-install:
.if !exists(${PREFIX}/etc/ssh_host_key)
	@${ECHO_MSG} ">> Generating an RSA secret host key."
	${PREFIX}/bin/ssh-keygen -N "" -f ${PREFIX}/etc/ssh_host_key
.endif
.if !exists(${PREFIX}/etc/ssh_host_dsa_key)
	@${ECHO_MSG} ">> Generating a DSA secret host key."
	${PREFIX}/bin/ssh-keygen -d -N "" -f ${PREFIX}/etc/ssh_host_dsa_key
.endif
.if !exists(${PREFIX}/etc/rc.d/sshd.sh)
	@${INSTALL_SCRIPT} ${WRKSRC}/sshd.sh ${PREFIX}/etc/rc.d/
.endif
.if !exists(${PREFIX}/etc/ssh_config) && !exists(${PREFIX}/etc/sshd_config)
	@cd ${WRKSRC}; \
	${MAKE} DESTDIR=${PREFIX} distribution
.else
	@${ECHO_MSG} ">> ${PREFIX}/etc/ssh{,d}_config exists, not being replaced!"
	@${ECHO_MSG} ">> If this is left over from another version of SSH, you will"
	@${ECHO_MSG} ">> need to update it to work with OpenSSH."
.endif

.include <bsd.port.post.mk>
