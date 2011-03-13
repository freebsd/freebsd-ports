# New ports collection makefile for:	ssh
# Date created:		30 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ssh
PORTVERSION=	1.2.33
PORTREVISION=	6
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/ \
		ftp://ftp.nsysu.edu.tw/Unix/Security/ssh/ \
		ftp://ftp.cronyx.ru/mirror/ssh/ \
		ftp://ftp.univie.ac.at/applications/ssh.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure shell client and server (remote login program)

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

CONFLICTS=	openssh-* openssh-portable-* openssh-gssapi-* ssh2-3.*
NO_LATEST_LINK=	YES
USE_AUTOTOOLS=	autoconf213
GNU_CONFIGURE=	YES
USE_PERL5=	YES
CONFIGURE_ENV+=	PERL=${PERL5}

CONFIGURE_ARGS+=--with-etcdir=${PREFIX}/etc

# Uncomment if all your users are in their own group and their homedir
# is writeable by that group.  Beware the security implications!
#
#CONFIGURE_ARGS+=	--enable-group-writeability

# Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
# over a secure medium (i.e. allow SSH connections without encryption).
# This is normally dangerous since it can lead to the disclosure of keys
# and passwords.
#
#CONFIGURE_ARGS+=	--with-none

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-kerberos5=${KRB5_HOME} --enable-kerberos-tgt-passing \
	--disable-suid-ssh
.endif

# Include support for the SecureID card
# Warning: untested !
#
.if defined(WITH_SECUREID)
CONFIGURE_ARGS+=	--with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a licence in a number of countries. Since SSH
# itself may not be used for commercial purposes without a license, we
# enable IDEA by default since the user would already be getting himself
# into trouble.
#
.if defined(WITHOUT_IDEA)
CONFIGURE_ARGS+=	--without-idea
.endif

LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
MAKE_ENV+=	GMPINCDIR="${LOCALBASE}/include" \
		GMPLIBDIR="${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if !defined(REALLY_WANT_SSH)
IGNORE=		is now deprecated: OpenSSH is a superior version of SSH which has been included in the FreeBSD base system since 4.0-RELEASE.  To override this warning set the REALLY_WANT_SSH environment variable and rebuild
.endif

MAN1=		scp1.1 ssh-add1.1 ssh-agent1.1 ssh-keygen1.1 ssh1.1 \
		make-ssh-known-hosts1.1
MAN8=		sshd1.8
MLINKS=		make-ssh-known-hosts1.1 make-ssh-known-hosts.1 \
		scp1.1 scp.1 \
		ssh-add1.1 ssh-add.1 \
		ssh-agent1.1 ssh-agent.1 \
		ssh-keygen1.1 ssh-keygen.1 \
		ssh1.1 ssh.1 \
		ssh.1 slogin.1 \
		ssh1.1 slogin1.1 \
		sshd1.8 sshd.8

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

post-install:
	@if [ ! -f ${PREFIX}/etc/ssh_host_key ]; then \
	    ${ECHO_MSG} "Generating a secret host key..."; \
	    ${PREFIX}/bin/ssh-keygen -f ${PREFIX}/etc/ssh_host_key -N ""; \
	fi; \
	if [ "`grep ssh /etc/inetd.conf|grep -v ^#ssh`" = "" ]; then \
	    if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		${SED} -e 's+!!PREFIX!!+${PREFIX}+g' ${FILESDIR}/sshd.sh \
		    > ${PREFIX}/etc/rc.d/sshd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	    fi; \
	fi

# Include tcp-wrapper support (call remote identd)
CONFIGURE_ARGS+=	--with-libwrap

# Original IPv6 patches were obtained from ftp://ftp.kyoto.wide.ad.jp/IPv6/ssh/
# ssh-1.2.27-IPv6-1.5-patch.gz
# We still use WITH_INET6 here and try to support pre 4.0 machines with kame
# IPv6 stack
.if defined(WITH_INET6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Include SOCKS firewall support
.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=	--with-socks="-L${PREFIX}/lib -lsocks5" --with-socks5
.endif

# Include extra files if X11 is installed
.if defined(WITH_X11) || (exists(${LOCALBASE}/lib/libX11.a) \
	&& !defined(WITHOUT_X11))
USE_XORG=	x11
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist.x11 ${PKGDIR}/pkg-plist > ${PLIST}
.else
CONFIGURE_ARGS+=	--without-x
.endif

.include <bsd.port.post.mk>
