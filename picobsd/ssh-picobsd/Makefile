# New ports collection makefile for:	ssh-picobsd
# Date created:		21 Apr 2001
# Whom:			luigi@FreeBSD.org
#
# $FreeBSD$
#
# A small version of ssh for picobsd. A single binary does ssh,sshd and scp
#

PORTNAME=	ssh
PORTVERSION=	1.2.27 # Note, 1.2.30 is under a more restrictive license
PORTREVISION=	1
CATEGORIES=	picobsd security
MASTER_SITES=	\
		ftp://ftp.ssh.com/pub/ssh/old/ \
		ftp://ftp.cronyx.ru/mirror/ssh/old/ \
		ftp://ftp.dei.uc.pt/pub/Crypto/SSH/old/ \
		ftp://ftp.nsysu.edu.tw/Unix/Security/ssh/old/

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	Secure shell client, server and remote copy (for picobsd)

NO_CDROM=	"Picobsd only"
NO_PACKAGE=	"This is only useful to build picobsd images"

BROKEN=		"Install fails"

USE_AUTOCONF_VER=	213
GNU_CONFIGURE=	YES
USE_PERL5=	YES
CONFIGURE_ENV+= PERL=${PERL5}

CONFIGURE_ARGS+= --with-etcdir=${PREFIX}/etc

# Uncomment if all your users are in their own group and their homedir
# is writeable by that group.  Beware the security implications!
#
#CONFIGURE_ARGS+= --enable-group-writeability

# Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
# over a secure medium (i.e. allow SSH connections without encryption).
# This is normally dangerous since it can lead to the disclosure of keys
# and passwords.
#
#CONFIGURE_ARGS+= --with-none

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-kerberos5=${KRB5_HOME} --enable-kerberos-tgt-passing \
	--disable-suid-ssh
.endif

# Include support for the SecureID card
# Warning: untested !
#
.if defined(WITH_SECUREID)
CONFIGURE_ARGS+= --with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a licence in a number of countries. Since SSH
# itself may not be used for commercial purposes without a license, we
# enable IDEA by default since the user would already be getting himself
# into trouble.

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

.include <bsd.port.pre.mk>

# no IDEA, tcpwrap, IPV6, SOCKS, x11 for picobsd
CONFIGURE_ARGS+= --disable-ipv6  --without-x --without-idea

.include <bsd.port.post.mk>
