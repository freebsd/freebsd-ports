# New ports collection makefile for:	ssh
# Version required:     1.2.14
# Date created:		30 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.25 1996/06/15 07:03:11 torstenb Exp $
#
# Maximal ssh package requires YES values for
# USE_PERL, USE_TCPWRAP
#

DISTNAME=       ssh-1.2.14
CATEGORIES=	security net
MASTER_SITES=   ftp://ftp.cs.hut.fi/pub/ssh/

MAINTAINER=	torstenb@FreeBSD.ORG

# You can set USA_RESIDENT appropriately in /etc/make.conf if this bugs you..

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
DISTFILES=	${DISTNAME}.tar.gz rsaref2.tar.gz
MASTER_SITES=	\
	ftp://ftp.cs.hut.fi/pub/ssh/ \
	ftp://nic.funet.fi/pub/crypt/mirrors/ftp.dsi.unimi.it/applied-crypto/ \
	ftp://rzsun2.informatik.uni-hamburg.de/pub/virus/crypt/ripem/ \
	ftp://ftp.dsi.unimi.it/pub/security/crypt/math/ \
	ftp://ftp.univie.ac.at/security/crypt/cryptography/asymmetric/rsa/ \
	ftp://isdec.vc.cvut.cz/pub/security/unimi/crypt/applied-crypto/
.endif

RESTRICTED=	"Crypto; export-controlled"
IS_INTERACTIVE=	YES

GNU_CONFIGURE=	YES

CONFIGURE_ARGS= --prefix=${PREFIX} --with-etcdir=${PREFIX}/etc

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
CONFIGURE_ARGS+= --with-rsaref
.endif

# Include SOCKS firewall support
# Warning: untested !
.if defined(USE_SOCKS) && ${USE_SOCKS} == YES
CONFIGURE_ARGS+= --with-socks
.endif

# Include support for the SecureID card
# Warning: untested !
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+= --with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a licence in a number of countried
# Warning: untested !
.if defined(DONT_USE_IDEA) && ${DONT_USE_IDEA} == YES
CONFIGURE_ARGS+= --without-idea
.endif

pre-patch:
	@mv -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

fetch-depends:
.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
	@echo
	@echo You must set variable USA_RESIDENT to YES if you are a USA
	@echo resident or NO otherwise.
	@echo If you are a USA resident you have to get the RSAREF2
	@echo library \(RSA Inc. holds a patent on RSA and public key
	@echo cypto in general - using RSA implementations other thann
	@echo RSAREF will violate the US patent law\)
	@echo and extract it to ${WRKSRC}.
	@false
.endif

post-extract:
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
	@mv ${WRKDIR}/rsaref2 ${WRKSRC}/rsaref2
.endif

post-install:
	gzip -9nf ${PREFIX}/man/man1/scp.1 ${PREFIX}/man/man1/ssh-add.1 \
		${PREFIX}/man/man1/ssh-agent.1 ${PREFIX}/man/man1/ssh-keygen.1 \
		${PREFIX}/man/man1/ssh.1 ${PREFIX}/man/man8/sshd.8 \
		${PREFIX}/man/man1/make-ssh-known-hosts.1
	@echo "---------------------------------------------------------------"
	@echo "If you are installing for the first time, do not forget to run:"
	@echo "   ssh-keygen -b 1024 -f $(PREFIX)/etc/ssh_host_key -N '' "
	@echo "---------------------------------------------------------------"
	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh; \
		echo "[ -x /usr/local/sbin/sshd ] && /usr/local/sbin/sshd && echo -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/sshd.sh; \
	fi

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand exists() properly

.if defined(USE_PERL) && ${USE_PERL} == YES || \
    exists(${PREFIX}/bin/perl5.002) && \
    (!defined(USE_PERL) || ${USE_PERL} != NO)
BUILD_DEPENDS+= perl5.002:${PORTSDIR}/lang/perl5
CONFIGURE_ENV+= PERL=${PREFIX}/bin/perl5.002
.else
CONFIGURE_ENV+= PERL=/replace_it_with_PERL_path
.endif

# Include tcp-wrapper support (call remote identd)
.if defined(USE_TCPWRAP) && ${USE_TCPWRAP} == YES || \
    exists(${PREFIX}/lib/libwrap.a) && \
    (!defined(USE_TCPWRAP) || ${USE_TCPWRAP} != NO)
CONFIGURE_ENV+= LDFLAGS=-L${PREFIX}/lib CFLAGS="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ARGS+= --with-libwrap
LIB_DEPENDS+=   wrap\\.7\\.:${PORTSDIR}/security/tcp_wrapper
.endif

