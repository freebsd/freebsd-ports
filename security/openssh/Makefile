# New ports collection makefile for:	OpenSSH
# Version required:	19991107
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

DISTNAME=	src/usr.bin/ssh
PKGNAME=	OpenSSH-1.2
CATEGORIES=	security net
# ${MASTER_SITES} is only for if CVS won't work, period.
MASTER_SITES=	ftp://internat.FreeBSD.org/pub/Crypto/misc/

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

RESTRICTED=	"Links with cryptographic code."

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CFLAGS+=	-DHAVE_OPENPTY
CVS_CMD?=	cvs -z3
CVS_DATE=	Sun Nov 21 11:22:08 EST 1999
SED?=		/usr/bin/sed
CVS_DATE_!=	${ECHO} -n ${CVS_DATE} | ${SED} 's/[ \t:]/_/g'
CVS_SITES=	anoncvs@anoncvs1.ca.openbsd.org:/cvs \
		:pserver:anoncvs@anoncvs1.usa.openbsd.org:/cvs
CRYPTOLIBS=	-L${PREFIX}/lib -lcrypto
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
CRYPTOLIBS+=	-lRSAglue -lrsaref
.endif
# Here, MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV=	DESTDIR=${PREFIX} MANDIR=/man/man CRYPTOLIBS="${CRYPTOLIBS}"
.if !exists(/usr/include/tcpd.h)
MAKE_ENV+=	TCP_WRAPPERS=no
.endif
.if defined(AFS) && ${AFS} == YES
MAKE_ENV+=	AFS=yes
.endif
.if defined(KERBEROS) && ${KERBEROS} == YES
MAKE_ENV+=	KERBEROS=yes
.endif
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
			${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS checkout from $${CVS_SITE}."; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
			    ${DISTNAME}; then \
				${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
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
	${ECHO_MSG" ">> ${_DISTDIR} and try again."; \
	exit 1

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${PKGNAME}/${DISTNAME} ${WRKDIR}
	@${CP} ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/

post-patch:
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/sshd_config
	@${PERL} -pi.openssl -e \
	    's:^(\s*#\s*include\s+<)ssl(/\w+\.h>\s*)$$:$$1openssl$$2:g' \
	    ${WRKSRC}/*.[ch]

post-install:
	@if [ ! -f ${PREFIX}/etc/ssh_config -a \
	      ! -f ${PREFIX}/etc/sshd_config ]; then \
		cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} distribution; \
	else \
		${ECHO_MSG} ">> ${PREFIX}/etc/ssh{,d}_config exists, not being replaced!"; \
		${ECHO_MSG} ">> If this is left over from another version of SSH, you will"; \
		${ECHO_MSG} ">> need to update it to work with OpenSSH."; \
	fi
.if !exists(${PREFIX}/etc/rc.d/sshd.sh)
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh
	@${ECHO} "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd && echo -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh
	@${CHMOD} 0555 ${PREFIX}/etc/rc.d/sshd.sh
.endif

.include <bsd.port.mk>
