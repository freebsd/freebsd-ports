# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	2.1.0p2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.hut.fi/pub/ssh/ \
		ftp://sunsite.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/security/ssh/
DISTNAME=	ssh-secure-shell-2.1.0-noncommercial

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ssh-2.1.0-patch1
PATCH_DIST_STRIP=	-p1

MAINTAINER=	issei@jp.FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --enable-debug
#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+= --enable-group-writeability

.include <bsd.port.pre.mk>

# Don't support for ssh1 client backward compatibility
#WITHOUT_SSH1=	yes
# Include tcp_wrappers support (automaticlly YES if /usr/include/tcpd.h exists)
#WITH_TCPWRAP=	yes
# Warning: untested!
# Include support for the TIS authentication server
#WITH_TIS=	yes
# Include support for the SecureID card
#WITH_SECUREID=	yes

.if ${OSVERSION} < 400016 && !defined(WITHOUT_SSH1)
BUILD_DEPENDS+=	ssh1:${PORTSDIR}/security/ssh
RUN_DEPENDS+=	ssh1:${PORTSDIR}/security/ssh
.endif

.if defined(WITH_SECUREID)
CONFIGURE_ARGS+= --with-secureid
.endif
.if defined(WITH_TIS)
CONFIGURE_ARGS+= --with-tis
.endif
.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+= --with-libwrap
.elif defined(WITH_TCPWRAP)
CONFIGURE_ARGS+= --with-libwrap="-L ${PREFIX}/lib -lwrap"
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

MAN1=	ssh-add2.1 ssh-agent2.1 scp2.1 sftp2.1 sshregex.1 ssh-probe2.1 \
	ssh-dummy-shell.1 ssh-pubkeymgr.1 ssh2.1 ssh-keygen2.1
MAN8=	sshd2.8

MLINKS=	scp2.1 scp.1 \
	sftp2.1 sftp.1 \
	ssh-add2.1 ssh-add.1 \
	ssh-agent2.1 ssh-agent.1 \
	ssh-keygen2.1 ssh-keygen.1 \
	ssh-probe2.1 ssh-probe.1 \
	ssh2.1 ssh.1  \
	sshd2.8 sshd.8

PORTDOCS=	BUG.REPORT CHANGES FAQ INSTALL LICENSING README \
		SSH2.QUICKSTART
.if ${OSVERSION} >= 400016 || defined(WITHOUT_SSH1)
PLIST=		${PKGDIR}/PLIST.ssh2_only
.endif

.if exists(/usr/sbin/sshd)
post-patch:
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/use-base-openssh.diff
.endif

post-install:
.if ${OSVERSION} < 400016 && !defined(WITHOUT_SSH1)
.for i in ssh ssh-keygen ssh-add ssh-agent scp
	${MV} -f ${PREFIX}/man/man1/${i}.1${MAN_SUFX} ${PREFIX}/man/man1/${i}.old.1${MAN_SUFX}
.endfor
	${MV} -f ${PREFIX}/man/man8/sshd.8${MAN_SUFX} ${PREFIX}/man/man8/sshd.old.8${MAN_SUFX}
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
		${SED} -e 's+!!PREFIX!!+${PREFIX}+' < ${FILESDIR}/sshd.sh \
			> ${PREFIX}/etc/rc.d/sshd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	fi

.include <bsd.port.post.mk>
