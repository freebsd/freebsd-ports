# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	2.3.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/ \
		ftp://sunsite.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/security/ssh/
DISTNAME=	ssh-${PORTVERSION}

MAINTAINER=	issei@jp.FreeBSD.org

#RESTRICTED=	"Crypto; export-controlled"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --disable-compiler-optimizations
#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+= --enable-group-writeability

.include <bsd.port.pre.mk>

# Include tcp_wrappers support (automaticlly YES if /usr/include/tcpd.h exists)
#WITH_TCPWRAP=	yes

.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+= --with-libwrap
.elif defined(WITH_TCPWRAP)
CONFIGURE_ARGS+= --with-libwrap="-L ${PREFIX}/lib -lwrap"
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

MAN1=	scp.1 sftp.1 scp2.1 sftp2.1 sshregex.1 ssh-probe2.1 ssh-dummy-shell.1 \
	ssh-pubkeymgr.1 ssh2.1 ssh-chrootmgr.1 ssh-agent.1 ssh-keygen.1 \
	ssh-add.1 ssh-add2.1 ssh-agent2.1 ssh-keygen2.1
MAN5=	ssh2_config.5 sshd2_config.5
MAN8=	sshd.8 sshd2.8

PORTDOCS=	BUG.REPORT CHANGES FAQ INSTALL LICENSE README \
		SSH2.QUICKSTART

post-install:
	${RM} ${PREFIX}/man/man1/ssh.1
	${RM} ${PREFIX}/man/man1/ssh-probe.1
.if !defined(NOPORTDOCS)
	-${MKDIR} ${PREFIX}/share/doc/ssh2
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/ssh2
.endfor
.endif
#
	@if [ "`grep ssh /etc/inetd.conf|grep -v ^#ssh`" = "" ]; then \
	    if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		${SED} -e 's+!!PREFIX!!+${PREFIX}+' < ${FILESDIR}/sshd.sh \
			> ${PREFIX}/etc/rc.d/sshd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	    fi; \
	fi

.include <bsd.port.post.mk>
