# New ports collection makefile for:	ssh
# Version required:	1.2.10
# Date created:		30 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.5 1995/11/22 13:20:15 asami Exp $
#

DISTNAME=	ssh-1.2.12
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/security/ \
		ftp://ftp.cs.hut.fi/pub/ssh/snapshots/

MAINTAINER=	torstenb@FreeBSD.ORG

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
DISTFILES=	${DISTNAME}.tar.gz rsaref2.tar.gz
MASTER_SITES=	\
	ftp://ftp.cs.hut.fi/pub/ssh/snapshots/ \
	ftp://ftp.funet.fi/pub/unix/security/ \
	ftp://nic.funet.fi/pub/crypt/mirrors/ftp.dsi.unimi.it/applied-crypto/ \
	ftp://rzsun2.informatik.uni-hamburg.de/pub/virus/crypt/ripem/ \
	ftp://ftp.dsi.unimi.it/pub/security/crypt/math/ \
	ftp://ftp.univie.ac.at/security/crypt/cryptography/asymmetric/rsa/ \
	ftp://isdec.vc.cvut.cz/pub/security/unimi/crypt/applied-crypto/
.endif

NO_PACKAGE=	YES
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

# Include tcp-wrapper support (call remote identd)
.if defined(USE_TCPWRAP) && ${USE_TCPWRAP} == YES
CONFIGURE_ENV=  LDFLAGS=-L${PREFIX}/lib CFLAGS="${CFLAGS} -I${PREFIX}/include"
BUILD_DEPENDS+= safe_finger:${PORTSDIR}/security/tcp_wrapper
CONFIGURE_ARGS+= --with-libwrap
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
	@echo resident.
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

.include <bsd.port.mk>
