# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	3.2.2
CATEGORIES=	security ipv6
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

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-etcdir=${SSH2_ETC} --disable-debug

SSH2_ETC=	${PREFIX}/etc/ssh2
SSH2_RCD=	${PREFIX}/etc/rc.d
CONFIG_FILES=	ssh2_config sshd2_config

# Uncomment if all your users are in their own group and their homedir
# is writeable by that group.  Beware the security implications!
#
#CONFIGURE_ARGS+=	--enable-group-writeability

# Kerberos support is untested.
#
#.if defined(KRB5_HOME) && exists(${KRB5_HOME})
#CONFIGURE_ARGS+=--with-kerberos5=${KRB5_HOME} --disable-suid-ssh-signer
#.endif

# Auto-configure tcp_wrappers support.
#
.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCPWRAP) && \
	!defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+=	--with-libwrap
.elif defined(WITH_TCPWRAP)
CONFIGURE_ARGS+=	--with-libwrap="-L${LOCALBASE}/lib -lwrap"

LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_X11) || (exists(${X11BASE}/lib/libX11.a) \
	&& !defined(WITHOUT_X11))
USE_XLIB=	yes
PLIST_SUB=	WITH_X11:=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB=	WITH_X11:="@comment "
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

PORTDOCS=	CHANGES FAQ INSTALL LICENSE MANIFEST NEWS README \
		REGEX-SYNTAX SSH2.QUICKSTART

post-install: install-config-files
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
	@if [ ! -f ${SSH2_ETC}/hostkey ]; then \
	    ${ECHO} "Generating a secret host key..."; \
	    ${PREFIX}/bin/ssh-keygen2 -P -b 1024 -t dsa ${SSH2_ETC}/hostkey; \
	fi; \
	if [ "`grep ssh /etc/inetd.conf|grep -v ^#ssh`" = "" ]; then \
	    if [ ! -f ${SSH2_RCD}/sshd.sh ]; then \
		${ECHO} "Installing ${SSH2_RCD}/sshd.sh startup file."; \
		${SED} -e 's+!!PREFIX!!+${PREFIX}+' < ${FILESDIR}/sshd.sh \
			> ${SSH2_RCD}/sshd.sh; \
		${CHMOD} 751 ${SSH2_RCD}/sshd.sh; \
	    fi; \
	fi

install-config-files:
.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/apps/ssh/${file} ${SSH2_ETC}/${file}.sample
.if !exists(${SSH2_ETC}/${file})
	${INSTALL_DATA} ${WRKSRC}/apps/ssh/${file} ${SSH2_ETC}
.endif
.endfor

.include <bsd.port.post.mk>
