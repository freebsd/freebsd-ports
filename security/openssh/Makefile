# New ports collection makefile for:	OpenSSH
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

PORTNAME=	OpenSSH
PORTVERSION=	1.2.2
CATEGORIES=	security net ipv6
# ${MASTER_SITES} is only for if CVS won't work, period.
MASTER_SITES=	ftp://internat.FreeBSD.org/pub/Crypto/OpenSSH/
DISTNAME=	src/usr.bin/ssh

MAINTAINER=	green@FreeBSD.org

USE_OPENSSL=	RSA

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
SED?=		/usr/bin/sed
DISTFILES!=	${SED} 's:^\(.*\)$$:${PKGNAME}/\1:g' ${FILESDIR}/distfiles
IGNOREFILES!=	${SED} 's:^\(.*\)$$:${PKGNAME}/\1:g' ${FILESDIR}/ignorefiles
DISTFILES+=	${IGNOREFILES}

CVS_CMD?=	cvs -z3
CVS_DATE=	Fri Mar  3 00:37:20 EST 2000
SED?=		/usr/bin/sed
CVS_DATE_!=	${ECHO} -n "${CVS_DATE}" | ${SED} 's/[ \t:]/_/g'
CVS_SITES?=	anoncvs@anoncvs1.ca.openbsd.org:/cvs \
		:pserver:anoncvs@anoncvs1.usa.openbsd.org:/cvs
CRYPTOLIBS=	-L${OPENSSLLIB} -lcrypto
.if defined(OPENSSL_RSAREF)
CRYPTOLIBS+=	-lRSAglue -L${LOCALBASE}/lib -lrsaref
.endif
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
STAMPFILE=	${DISTDIR}/${PKGNAME}/.stamp
WRKSRC=		${WRKDIR}/ssh

do-fetch:
	@if [ ! -e ${STAMPFILE} ] || \
	    [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		if [ -e ${DISTDIR}/${PKGNAME}.${CVS_DATE_}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${PKGNAME}.${CVS_DATE_}.tar.gz \
			    ${DISTFILES}; \
			${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		if [ -n "${PORTS_CVS_SERVER}" ]; then \
			export CVS_SERVER="${PORTS_CVS_SERVER}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS checkout from $${CVS_SITE}."; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
			    ${DISTNAME}; then \
				${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
				exit; \
			fi \
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}.  Please try to retrieve"; \
		${ECHO_MSG} ">> a snapshot with \"make fetchsrctarball\" and try again."; \
		exit 1; \
	fi

makesrctarball: fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${PKGNAME}.${CVS_DATE_}.tar.gz\"."; \
	${TAR} cfz ${PKGNAME}.${CVS_DATE_}.tar.gz ${PKGNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${PKGNAME}.${CVS_DATE_}.tar.gz; \
	if [ -e $$file ]; then \
		exit; \
	fi; \
	${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
	for site in ${MASTER_SITES}; do \
		${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
		if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		    $${site}$${file}; then \
			exit; \
		fi; \
	done; \
	${ECHO_MSG} ">> Couldn't fetch $$file."; \
	${ECHO_MSG} ">> Please try to retrieve this file manually into"; \
	${ECHO_MSG} ">> ${_DISTDIR} and try again."; \
	exit 1

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${PKGNAME}/${DISTNAME} ${WRKDIR}
	@${CP} ${FILESDIR}/strlcat.c ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/
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
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h \
		${WRKSRC}/sshd_config ${WRKSRC}/pam_ssh/pam_ssh.c
	@${PERL} -pi -e \
	    's:^(\s*#\s*include\s+<)ssl(/\w+\.h>\s*)$$:$$1openssl$$2:g' \
	    ${WRKSRC}/*.[ch]

.if ${PAM} == yes
PLIST=		${WRKDIR}/PLIST

do-configure:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
	@${ECHO} "@cwd /usr" >> ${PLIST}
	@${ECHO} "lib/pam_ssh.so" >> ${PLIST}
.endif

post-install:
.if !exists(${PREFIX}/etc/ssh_host_key)
	@${ECHO_MSG} ">> Generating a secret host key."
	${PREFIX}/bin/ssh-keygen -N "" -f ${PREFIX}/etc/ssh_host_key
.endif
.if !exists(${PREFIX}/etc/rc.d/sshd.sh)
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh
	@${ECHO} "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd && echo -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh
	@${CHMOD} 0555 ${PREFIX}/etc/rc.d/sshd.sh
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
