# New ports collection makefile for:	ssh2
# Date created:		5 Oct 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	3.2.9.1
PORTREVISION=	1
CATEGORIES=	security ipv6
# The list of official mirror sites is at:
# http://www.ssh.com/support/downloads/secureshellserver/non-commercial.html
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/ \
		ftp://ftp.wiretapped.net/pub/security/cryptography/apps/ssh/SSH/ \
		http://www.mirrors.wiretapped.net/security/cryptography/apps/ssh/SSH/ \
		ftp://gd.tuwien.ac.at/utils/shells/ssh/ \
		ftp://ftp.ut.ee/pub/unix/security/ssh/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.ssh.com/pub/ssh/ \
		ftp://ftp.crihan.fr/mirrors/ftp.ssh.com/ \
		http://ftp.crihan.fr/mirrors/ftp.ssh.com/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/ssh/ \
		ftp://ftp.ntua.gr/pub/security/ssh/ \
		ftp://ftp.unina.it/pub/Unix/ssh/ \
		ftp://ftp.win.ne.jp/pub/ssh/ \
		ftp://core.ring.gr.jp/pub/net/ssh/ \
		http://core.ring.gr.jp/archives/net/ssh/ \
		ftp://ftp.ring.gr.jp/pub/net/ssh/ \
		http://www.ring.gr.jp/archives/net/ssh/ \
		ftp://ftp.ayamura.org/pub/ssh/ \
		ftp://linux.sarang.net/mirror/network/daemon/security/ssh/ \
		ftp://giswitch.sggw.waw.pl/pub/ssh/ \
		ftp://ftp.wsisiz.edu.pl/pub/Unix/ssh/ \
		ftp://ftp.kreonet.re.kr/pub/security/ssh/ \
		ftp://ftp.ulak.net.tr/ssh/ \
		ftp://metalab.unc.edu/pub/packages/security/ssh/ \
		ftp://ftp.in-span.net/pub/mirrors/ftp.ssh.com/ \
		ftp://ftp.keystealth.org/pub/ssh/ \
		ftp://ftp.epix.net/pub/ssh/ \
		ftp://mirror.pa.msu.edu/ssh/
DISTNAME=	ssh-${PORTVERSION}

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	Secure shell client and server for V.2 SSH protocol

CONFLICTS=	openssh-* openssh-portable-* openssh-gssapi-* ssh-1.*

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
MANCOMPRESSED=	no

MAN1=		ssh2.1 ssh-keygen2.1 ssh-add2.1 ssh-agent2.1 scp2.1 sftp2.1 \
		sshregex.1 ssh-probe2.1 ssh-dummy-shell.1
MAN5=		ssh2_config.5 sshd-check-conf.5 sshd2_config.5 \
		sshd2_subconfig.5
MAN8=		sshd2.8
MLINKS=		ssh2.1 ssh.1 ssh-add2.1 ssh-add.1 ssh-agent2.1 ssh-agent.1 \
		ssh-keygen2.1 ssh-keygen.1 scp2.1 scp.1 sftp2.1 sftp.1 \
		ssh-probe2.1 ssh-probe.1 sshd2.8 sshd.8
DOCS=		CHANGES FAQ HOWTO.anonymous.sftp LICENSE NEWS README \
		REGEX-SYNTAX SSH2.QUICKSTART \
		RFC.authorization_program_protocol RFC.kbdint_plugin_protocol
EXAMPLES=	ext_authorization_example.sh kbdint_plugin_example.sh

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-debug --with-foreign-etcdir=${PREFIX}/etc \
			--with-libwrap
PKGMESSAGE=		${WRKDIR}/pkg-message

# Define if all your users are in their own group and their homedir
# is writeable by that group.  Beware the security implications!
#
.if defined(WITH_GROUP_WRITEABILITY)
CONFIGURE_ARGS+=	--enable-group-writeability
.endif

# Kerberos5 support in ssh2 is EXPERIMENTAL and requires MIT Kerberos,
# Heimdal is unsupported.
#
.if !defined(WITHOUT_KERBEROS) && defined(KRB5_HOME) && \
	exists(${KRB5_HOME}/lib/libk5crypto.a)
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5_HOME} --disable-suid-ssh-signer
EXTRA_PATCHES+=		${FILESDIR}/kerberos-patch-apps::ssh::ssh2_config \
			${FILESDIR}/kerberos-patch-apps::ssh::sshd2_config
.endif

.if defined(WITH_X11) || (exists(${X11BASE}/lib/libX11.a) \
	&& exists(${X11BASE}/bin/xauth) && !defined(WITHOUT_X11))
USE_XLIB=		yes
PLIST_SUB+=		WITH_X11:=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		WITH_X11:="@comment "
.endif

post-patch:
.for i in ${MAN1} ${MAN5} ${MAN8} ssh2_config sshd2_config
	@${REINPLACE_CMD} -e 's|\/etc\/ssh2|${PREFIX}&|g; \
		s|\/usr\/local|${LOCALBASE}|g' \
		${WRKSRC}/apps/ssh/${i}
.endfor
.for i in anonymous.example host_ext.example host_int.example
	@${REINPLACE_CMD} -e 's|\/etc\/ssh2|${PREFIX}&|g' \
		${WRKSRC}/apps/ssh/subconfig/${i}
.endfor
	@${REINPLACE_CMD} -e 's|\/etc\/ssh2|${PREFIX}&|g' \
		${WRKSRC}/HOWTO.anonymous.sftp
	@${REINPLACE_CMD} -E -e 's|\$$\(ETCDIR\)|${PREFIX}\/etc|g' \
		${WRKSRC}/apps/ssh/ssh_dummy_shell.out
	@${REINPLACE_CMD} -E -e 's|(^TESTS.+)(t-filecopy)|\1|g' \
		${WRKSRC}/apps/ssh/tests/Makefile.in
	@${REINPLACE_CMD} -E -e 's|(^ETCDIR=).+|\1${PREFIX}\/etc\/ssh2|; \
		s|(^SBINDIR=).+|\1${PREFIX}\/sbin|' \
		${WRKSRC}/startup/solaris/sshd2
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' \
		${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/startup/solaris/sshd2 \
		${PREFIX}/etc/rc.d/sshd2.sh.sample
	@${MKDIR} ${EXAMPLESDIR}
.for i in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/$i ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
	@if [ "`${GREP} ssh /etc/inetd.conf | ${GREP} -v ^#ssh`" = "" ]; then \
	    if [ ! -f ${PREFIX}/etc/rc.d/sshd2.sh ]; then \
		${ECHO_CMD} "Installing ${PREFIX}/etc/sshd2.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/startup/solaris/sshd2 \
			${PREFIX}/etc/rc.d/sshd2.sh; \
	    fi; \
	fi
	@${CAT} ${WRKDIR}/pkg-message

test:	build
	@-cd ${WRKSRC}/lib/sshcrypto/tests && ${MAKE} check-TESTS
	@-cd ${WRKSRC}/apps/ssh/lib/sshproto/tests && ${MAKE} check-TESTS
	@-cd ${WRKSRC}/apps/ssh/tests && ${MAKE} check-TESTS

.include <bsd.port.post.mk>
