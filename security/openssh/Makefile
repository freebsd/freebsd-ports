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
MASTER_SITES=	# See ${CVS_SITES}

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

RESTRICTED=	"Links with cryptographic code."

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CVS_CMD?=	cvs -z3
CVS_DATE=	Wed Nov 17 14:09:01 EST 1999
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
		unset CVS_RSH CVS_SERVER || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME} || exit; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS checkout from $${CVS_SITE}."; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
			    ${DISTNAME}; then \
				${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
				exit; \
			fi \
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}.  Please try to retrieve"; \
		${ECHO_MSG} ">> this port manually into ${_DISTDIR} and try again."; \
		exit 1; \
	fi

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${PKGNAME}/${DISTNAME} ${WRKDIR}
	@${CP} ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/

post-patch:
	@${PERL} -pi.orig -e 's:(_PATH_STDPATH):$$1 "${PREFIX}/bin":g' \
	    ${WRKSRC}/sshd.c
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/sshd_config
	@${PERL} -pi.openssl -e \
	    's:^(\s*#\s*include\s+<)ssl(/\w+\.h>\s*)$$:$$1openssl$$2:g' \
	    ${WRKSRC}/*.[ch]

pre-install:
	@if [ ! -f ${PREFIX}/etc/sshd_config ]; then \
		cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} distribution; \
	else \
		${ECHO_MSG} ">> ${PREFIX}/etc/sshd_config exists, not being replaced!"; \
		${ECHO_MSG} ">> If this is left over from another version of SSH, you will"; \
		${ECHO_MSG} ">> need to update it to work with OpenSSH."; \
	fi

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		${ECHO_MSG} ">> Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		${MKDIR} ${PREFIX}/etc/rc.d; \
		${INSTALL_SCRIPT} ${FILESDIR}/sshd.sh \
		    ${PREFIX}/etc/rc.d; \
		${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' \
		    ${PREFIX}/etc/rc.d/sshd.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/ssh_host_key ]; then \
		${ECHO_MSG} "Generating a secret host key..."; \
		${PREFIX}/bin/ssh-keygen -N "" -f ${PREFIX}/etc/ssh_host_key; \
	fi


.include <bsd.port.mk>
