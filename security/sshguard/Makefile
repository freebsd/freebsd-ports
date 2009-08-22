# New ports collection makefile for:	sshguard
# Date created:		2007-02-22
# Whom:			Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	sshguard
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	SF/sshguard/sshguard/sshguard-${PORTVERSION}

MAINTAINER=	mij@bitchx.it
COMMENT?=	Protect hosts from brute force attacks against ssh and other services

CONFLICTS?=	sshguard-ipfilter-1.* sshguard-ipfw-1.* sshguard-pf-1.*

PLIST_FILES=	sbin/sshguard

MAN8=		sshguard.8
MANCOMPRESSED=	no
USE_BZIP2=	yes
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
HAS_CONFIGURE=	yes

# sublist will be set afterward
SUB_FILES=	pkg-message

# backend type in { hosts, ipfw, pf }
SSHGUARDFW?=	hosts

.include <bsd.port.pre.mk>

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

# set path for manpages
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

.if ${SSHGUARDFW} == pf
PKGMSG_FWBLOCK="  To activate or configure PF see http://sshguard.sf.net/doc/setup/blockingpf.html"
.elif ${SSHGUARDFW} == ipfw
PKGMSG_FWBLOCK="  Verify that IPFW is active with \"ipfw show\"."
.elif ${SSHGUARDFW} == hosts
PKGMSG_FWBLOCK="  Sshguard is going to use /etc/hosts.allow, I have touched it for you."
.elif ${SSHGUARDFW} == ipfilter
PKGMSG_FWBLOCK="  Sshguard will use /etc/ipf.rules as ruleset."
.endif

# for substitution in subfiles
SUB_LIST+=	PKGMSG_FWBLOCK=${PKGMSG_FWBLOCK}

CONFIGURE_ARGS+=	--with-firewall=${SSHGUARDFW}

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT}	${PKGMESSAGE}

pre-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} DEINSTALL

.include <bsd.port.post.mk>
