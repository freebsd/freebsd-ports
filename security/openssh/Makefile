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

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

RESTRICTED=	"Links with cryptographic code."

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CVS_CMD?=	cvs -z3
CVS_DATE=	Fri Nov 12 20:27:53 EST 1999
CVS_SITE?=	anoncvs@anoncvs1.ca.openbsd.org:/cvs
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
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME} && \
		${CVS_CMD} -d ${CVS_SITE} co -D "${CVS_DATE}" ${DISTNAME} && \
		${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
	fi

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${PKGNAME}/${DISTNAME} ${WRKDIR}
	@${CP} ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/

post-patch:
	@${PERL} -pi.orig -e 's:_PATH_STDPATH:_PATH_STDPATH "${PREFIX}/bin":' \
		${WRKSRC}/sshd.c
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/ssh.h
	@${PERL} -pi.orig -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/sshd_config

pre-install:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} distribution

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd &&" \
			"${ECHO} -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh; \
		${CHMOD} 755 ${PREFIX}/etc/rc.d/sshd.sh; \
	fi

.include <bsd.port.mk>
