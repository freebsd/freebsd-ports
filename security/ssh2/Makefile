# New ports collection makefile for:	ssh2
# Version required:     2.0.*
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $Id: Makefile,v 1.75 1998/12/01 11:10:33 obrien Exp $
#
# Maximal ssh2 package requires YES values for
# USE_SSH1, USE_TCPWRAP

DISTNAME=       ssh-2.0.12
CATEGORIES=	security net
MASTER_SITES=   ftp://ftp.cs.hut.fi/pub/ssh/ \
		ftp://sunsite.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/security/ssh/

MAINTAINER=	issei@jp.FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS= --prefix=${PREFIX} --with-etcdir=${PREFIX}/etc --enable-debug
#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+= --enable-group-writeability
#
# Include support for ssh1 client backward compatibility
.if defined(USE_SSH1) && ${USE_SSH1} == YES
BUILD_DEPENDS+=	ssh1:${PORTSDIR}/security/ssh
RUN_DEPENDS+=	ssh1:${PORTSDIR}/security/ssh
.endif
# Warning: untested !
# Include support for the SecureID card
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+= --with-secureid
.endif
.if defined(USE_TIS) && ${USE_TIS} == YES
# Include support for the TIS authentication server
CONFIGURE_ARGS+= --with-tis
.endif
# Include tcp_wrappers support
.if defined(USE_TCPWRAP) && ${USE_TCPWRAP} == YES
CONFIGURE_ARGS+= --with-libwrap="-L ${PREFIX}/lib -lwrap"
LIB_DEPENDS+=   wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

MAN1=	ssh2.1 ssh-keygen2.1 ssh-add2.1 ssh-agent2.1 \
	scp2.1 sftp2.1
MAN8=	sshd2.8

USE_SSH1?=	YES
USE_TCPWRAP?=	NO
USE_TIS?=	NO
USE_SECUREID?=	NO
PORTDOCS=	CHANGES LICENSING README
.if !defined(USE_SSH1) || (defined(USE_SSH1) && ${USE_SSH1} != YES)
PLIST=		${PKGDIR}/PLIST.ssh2_only
.endif
.if defined(NOMANCOMPRESS)
MAN_SUFX=	""
.else
MAN_SUFX=	.gz
.endif

post-install:
.if defined(USE_SSH1) && ${USE_SSH1} == YES
.for i in ssh ssh-keygen ssh-add ssh-agent scp
	${MV} -f ${PREFIX}/man/man1/${i}.1${MAN_SUFX} ${PREFIX}/man/man1/${i}.old.1${MAN_SUFX}
.endfor
	${MV} -f ${PREFIX}/man/man8/sshd.8${MAN_SUFX} ${PREFIX}/man/man8/sshd.old.8${MAN_SUFX}
.endif
#
.if !defined(NOMANCOMPRESS)
.for i in ssh ssh-keygen ssh-add ssh-agent scp sftp
	${RM} -f ${PREFIX}/man/man1/${i}.1
	${LN} -sf ${i}2.1.gz ${PREFIX}/man/man1/${i}.1.gz
.endfor
	${RM} -f ${PREFIX}/man/man8/sshd.8
	${LN} -sf sshd2.8.gz ${PREFIX}/man/man8/sshd.8.gz
.endif
#
.if !defined(NOPORTDOCS)
	-${MKDIR} ${PREFIX}/share/doc/ssh2
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/ssh2
.endfor
.endif
#
	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd && ${ECHO} -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	fi

.include <bsd.port.mk>
