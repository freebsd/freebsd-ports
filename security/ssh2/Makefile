# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	3.2.5
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/ \
		ftp://sunsite.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.keystealth.org/pub/ssh/ \
		ftp://metalab.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.nsysu.edu.tw/Unix/Security/ssh/ \
		ftp://ftp.cronyx.ru/mirror/ssh/ \
		ftp://ftp.univie.ac.at/applications/ssh.com/
DISTNAME=	ssh-${PORTVERSION}

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	Secure shell client and server (remote login program)

CONFLICTS=	openssh-* openssh-portable-* openssh-gssapi-* ssh-1.*
GNU_CONFIGURE=	YES
USE_REINPLACE=	YES

CONFIGURE_ARGS=	--with-etcdir=${SSH2_ETC} --disable-debug

SSH2_ETC=	${PREFIX}/etc/ssh2
SSH2_RCD=	${PREFIX}/etc/rc.d
CONFIG_FILES=	ssh2_config sshd2_config

.include <bsd.port.pre.mk>

# Define if all your users are in their own group and their homedir
# is writeable by that group.  Beware the security implications!
#
.if defined(WITH_GROUP_WRITEABILITY)
CONFIGURE_ARGS+=	--enable-group-writeability
.endif

# Kerberos5 support in ssh2 is EXPERIMENTAL and requires MIT Kerberos,
# Heimdal is unsupported.
#
.if defined(WITH_KERBEROS) && defined(KRB5_HOME) && \
	exists(${KRB5_HOME}/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5_HOME} --disable-suid-ssh-signer
.endif

.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+=	--with-libwrap
.endif

# This is necessary for a working ssh-chrootmgr. Added by mic@nethack.at.
#
.if defined(WITH_STATIC_SFTP)
CONFIGURE_ARGS+=	--enable-static
PLIST_SUB=		STATIC=""
.else
PLIST_SUB=		STATIC="@comment "
.endif

.if defined(WITH_X11) || (exists(${X11BASE}/lib/libX11.a) \
	&& exists(${X11BASE}/bin/xauth) && !defined(WITHOUT_X11))
USE_XLIB=	yes
PLIST_SUB+=	WITH_X11:=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	WITH_X11:="@comment "
.endif

MAN1=		ssh2.1 ssh-keygen2.1 ssh-add2.1 ssh-agent2.1 scp2.1 sftp2.1 \
		sshregex.1 ssh-probe2.1 ssh-dummy-shell.1
MAN5=		ssh2_config.5 sshd-check-conf.5 sshd2_config.5 \
		sshd2_subconfig.5
MAN8=		sshd2.8
MLINKS=		ssh2.1 ssh.1 ssh-add2.1 ssh-add.1 ssh-agent2.1 ssh-agent.1 \
		ssh-keygen2.1 ssh-keygen.1 scp2.1 scp.1 sftp2.1 sftp.1 \
		ssh-probe2.1 ssh-probe.1 sshd2.8 sshd.8
MANCOMPRESSED=	no

PORTDOCS=	CHANGES FAQ INSTALL LICENSE MANIFEST NEWS README \
		REGEX-SYNTAX SSH2.QUICKSTART

post-patch:
.for i in ${MAN1} ${MAN5} ${MAN8}
	@${REINPLACE_CMD} -e 's|\/etc\/ssh2|${PREFIX}&|g;' \
		${WRKSRC}/apps/ssh/${i}
.endfor
	@${REINPLACE_CMD} -E -e 's|\$$\(ETCDIR\)|${PREFIX}\/etc|g;' \
		${WRKSRC}/apps/ssh/ssh_dummy_shell.out

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
	if [ "`${GREP} ssh /etc/inetd.conf | ${GREP} -v ^#ssh`" = "" ]; then \
	    if [ ! -f ${SSH2_RCD}/sshd.sh ]; then \
		${ECHO} "Installing ${SSH2_RCD}/sshd.sh startup file."; \
		${SED} -e 's+!!PREFIX!!+${PREFIX}+' < ${FILESDIR}/sshd.sh \
			> ${SSH2_RCD}/sshd.sh; \
		${CHMOD} 751 ${SSH2_RCD}/sshd.sh; \
	    fi; \
	fi

.include <bsd.port.post.mk>
