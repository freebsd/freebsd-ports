# New ports collection makefile for:	ssh
# Version required:     1.2.25
# Date created:		30 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.71 1998/10/30 06:15:18 obrien Exp $
#
# Maximal ssh package requires YES values for
# USE_PERL, USE_TCPWRAP
#

DISTNAME=       ssh-1.2.26
CATEGORIES=	security net
MASTER_SITES=   ftp://ftp.funet.fi/pub/unix/security/login/ssh/

MAINTAINER=	torstenb@FreeBSD.ORG

# You can set USA_RESIDENT appropriately in /etc/make.conf if this bugs you..

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
MASTER_SITES=	\
	ftp://ftp.funet.fi/pub/unix/security/login/ssh/ \
	ftp://nic.funet.fi/pub/crypt/mirrors/ftp.dsi.unimi.it/applied-crypto/ \
	ftp://rzsun2.informatik.uni-hamburg.de/pub/virus/crypt/ripem/ \
	ftp://idea.sec.dsi.unimi.it/pub/security/crypt/math/ \
	ftp://ftp.univie.ac.at/security/crypt/cryptography/asymmetric/rsa/ \
	ftp://isdec.vc.cvut.cz/pub/security/unimi/crypt/applied-crypto/

CONFIGURE_ARGS+= --with-rsaref
LIB_DEPENDS+=	rsaref.2:${PORTSDIR}/security/rsaref
BUILD_DEPENDS+= /nonexistent:${PORTSDIR}/security/rsaref:extract
.endif

#
# Use Phil Karn's asm patches to speed up DES on intel.
# Download by hand from http://www.cryptography.org/cgi-bin/crypto.cgi/ssh/  
# and put in distfiles directory.
#
# Disabled for now, since there's not such a patchkit for 1.2.25 version.
#.if defined(FAST_DES_PATCHKIT) && ${FAST_DES_PATCHKIT} == YES
#PATCHFILES=ssh-1.2.22-patchkit
#PATCH_DIST_STRIP=-p1
#.endif

RESTRICTED=	"Crypto; export-controlled"
IS_INTERACTIVE=	YES

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --with-etcdir=${PREFIX}/etc

#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+= --enable-group-writeability

#Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
#over a secure medium.  This is normally dangerous since it can lead to the
#disclosure keys and passwords.
#CONFIGURE_ARGS+= --with-none

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-kerberos5=${KRB5_HOME} --enable-kerberos-tgt-passing
.endif

# Include support for the SecureID card
# Warning: untested !
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+= --with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a licence in a number of countries
# Warning: untested !
.if defined(DONT_USE_IDEA) && ${DONT_USE_IDEA} == YES
CONFIGURE_ARGS+= --without-idea
.endif

.if !exists(${X11BASE}/bin/xauth)
CONFIGURE_ARGS+= --without-x
.endif

MAN1=		scp1.1 ssh-add1.1 ssh-agent1.1 ssh-keygen1.1 ssh1.1 \
		make-ssh-known-hosts1.1
MAN8=		sshd1.8


pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

fetch-depends:
.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
	@echo
	@echo You must set the variable USA_RESIDENT to YES if you are a
	@echo United States resident, otherwise NO.
	@echo If you are a US resident then this port must also fetch
	@echo the RSAREF2 library from sources abroad \(RSA Inc. holds a
	@echo patent on RSA and public key crypto in general in the United
	@echo States so using RSA implementations other than RSAREF there
	@echo may violate US patent law\).
	@false
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/ssh_host_key ]; then \
		echo "Generating a secret host key..."; \
		${PREFIX}/bin/ssh-keygen -f ${PREFIX}/etc/ssh_host_key -N ""; \
	fi
.if !defined(NOMANCOMPRESS)
	for file in make-ssh-known-hosts scp ssh-add ssh-agent \
	    ssh-keygen ssh; do \
		rm -f ${PREFIX}/man/man1/$${file}.1; \
		ln -sf $${file}1.1.gz ${PREFIX}/man/man1/$${file}.1.gz; \
	done
	rm -f ${PREFIX}/man/man1/slogin.1
	rm -f ${PREFIX}/man/man1/slogin1.1
	rm -f ${PREFIX}/man/man8/sshd.8
	ln -sf ssh.1.gz ${PREFIX}/man/man1/slogin.1.gz
	ln -sf ssh1.1.gz ${PREFIX}/man/man1/slogin1.1.gz
	ln -sf sshd1.8.gz ${PREFIX}/man/man8/sshd.8.gz
.else
	${ECHO} Warning---some manpages not installed.  See port Makefile
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh; \
		echo "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd && echo -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	fi

.include <bsd.port.pre.mk>

.if defined(USE_PERL) && ${USE_PERL} == YES || \
    exists(${PERL5}) && (!defined(USE_PERL) || ${USE_PERL} != NO)
USE_PERL5=	yes
CONFIGURE_ENV+= PERL=${PERL5}
.else
CONFIGURE_ENV+= PERL=/replace_it_with_PERL_path
.endif

# Include tcp-wrapper support (call remote identd)
.if defined(USE_TCPWRAP) && ${USE_TCPWRAP} == YES || \
    exists(${PREFIX}/lib/libwrap.a) && \
    (!defined(USE_TCPWRAP) || ${USE_TCPWRAP} != NO)
CONFIGURE_ENV+= LDFLAGS=-L${PREFIX}/lib CFLAGS="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ARGS+= --with-libwrap
LIB_DEPENDS+=   wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && ${USE_SOCKS} == YES
CONFIGURE_ARGS+= --with-socks="-L${PREFIX}/lib -lsocks5" --with-socks5
.endif

.include <bsd.port.post.mk>
