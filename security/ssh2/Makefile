# New ports collection makefile for:	ssh
# Version required:     1.2.12a
# Date created:		30 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.11 1996/01/25 02:08:25 ache Exp $
#

DISTNAME=       ssh-1.2.12a
CATEGORIES=	security net
MASTER_SITES=   ftp://ftp.cs.hut.fi/pub/ssh/snapshots/
LIB_DEPENDS=    z\\.0\\.:${PORTSDIR}/devel/libz
BUILD_DEPENDS+= perl5.001:${PORTSDIR}/lang/perl5

MAINTAINER=	torstenb@FreeBSD.ORG

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
DISTFILES=	${DISTNAME}.tar.gz rsaref2.tar.gz
MASTER_SITES=	\
	ftp://ftp.cs.hut.fi/pub/ssh/snapshots/ \
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

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand exists() properly

.if exists(${X11BASE}/bin/xauth)
.if exists(${PREFIX}/bin/wish4.0)
BUILD_DEPENDS+= wish4.0:${PORTSDIR}/x11/tk4
CONFIGURE_ENV+= WISH=${PREFIX}/bin/wish4.0
.else
BUILD_DEPENDS+= wish:${PORTSDIR}/x11/tk
.endif
.else
CONFIGURE_ENV+= WISH=/replace_it_with_WISH_path
.endif

# Include tcp-wrapper support (call remote identd)
.if defined(USE_TCPWRAP) && ${USE_TCPWRAP} == YES || \
    exists(${PREFIX}/lib/libwrap.a) && \
    (!defined(USE_TCPWRAP) || ${USE_TCPWRAP} != NO)
CONFIGURE_ENV+= LDFLAGS=-L${PREFIX}/lib CFLAGS="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ARGS+= --with-libwrap
LIB_DEPENDS+=   wrap\\.7\\.:${PORTSDIR}/security/tcp_wrapper
.endif

