# New ports collection makefile for:	sshguard
# Date created:		2007-02-22
# Whom:			Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	sshguard
DISTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mij@bitchx.it
COMMENT?=	Protect hosts from brute force attacks against ssh

CONFLICTS?=	sshguard-ipfw-1.0* sshguard-pf-1.0*

PLIST_FILES=	sbin/sshguard

MAN8=		sshguard.8
MANCOMPRESSED=	no
USE_BZIP2=	yes
HAS_CONFIGURE=	yes

# sublist will be set afterward
SUB_FILES=	pkg-message
#SUB_LIST=

# backend type in { hosts, ipfw, pf }
SSHGUARDFW?=	hosts

.include <bsd.port.pre.mk>

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.if ${SSHGUARDFW} == pf
PKGMSG_FWBLOCK="  To activate or configure PF see http://sshguard.sf.net/doc/setup/blockingpf.html"
.elif ${SSHGUARDFW} == ipfw
PKGMSG_FWBLOCK="  Verify that IPFW is active with \"ipfw show\"."
.elif ${SSHGUARDFW} == hosts
PKGMSG_FWBLOCK="  Sshguard is going to use /etc/hosts.allow, I have touched it for you."
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
