# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	3.1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/ \
		ftp://sunsite.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/security/ssh/ \
		ftp://ftp.cis.fed.gov/pub/ssh/ \
		ftp://ftp.keystealth.org/pub/ssh/ \
		ftp://mirror.chpc.utah.edu/pub/ssh/ \
		ftp://metalab.unc.edu/pub/packages/security/ssh/ \
		ftp://herbie.ucs.indiana.edu/pub/security/ssh/
DISTNAME=	ssh-${PORTVERSION}

MAINTAINER=	larse@ISI.EDU

#RESTRICTED=	"Crypto; export-controlled"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc/ssh2
#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+=	--enable-group-writeability

.include <bsd.port.pre.mk>

# Include tcp_wrappers support (automaticlly YES if /usr/include/tcpd.h exists)
#WITH_TCPWRAP=	yes

.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+=	--with-libwrap
.elif defined(WITH_TCPWRAP)
CONFIGURE_ARGS+=	--with-libwrap="-L${LOCALBASE}/lib -lwrap"
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

MAN1=		ssh2.1 ssh-keygen2.1 ssh-add2.1 ssh-agent2.1 scp2.1 sftp2.1 \
		sshregex.1 ssh-probe2.1 ssh-dummy-shell.1 ssh-pubkeymgr.1 \
		ssh-chrootmgr.1
MAN5=		ssh2_config.5 sshd-check-conf.5 sshd2_config.5
MAN8=		sshd2.8
MLINKS=		ssh2.1 ssh.1 ssh-add2.1 ssh-add.1 ssh-agent2.1 ssh-agent.1 \
		ssh-keygen2.1 ssh-keygen.1 scp2.1 scp.1 sftp2.1 sftp.1 \
		ssh-probe2.1 ssh-probe.1 sshd2.8 sshd.8
MANCOMPRESSED=	no

PORTDOCS=	BUG.REPORT CHANGES FAQ INSTALL LICENSE MANIFEST NEWS README \
		REGEX-SYNTAX SSH2.QUICKSTART

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
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
