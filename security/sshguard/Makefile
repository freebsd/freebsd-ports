# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	sshguard
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF/sshguard/sshguard/sshguard-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT?=	Protect hosts from brute force attacks against ssh and other services

CONFLICTS?=	sshguard-ipfilter-1.* sshguard-ipfw-1.* sshguard-pf-1.*

USES=		tar:bzip2

PLIST_FILES=	sbin/sshguard man/man8/sshguard.8.gz

USE_RC_SUBR=	sshguard
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-firewall=${SSHGUARDFW}

SUB_LIST+=	PKGMSG_FWBLOCK=${PKGMSG_FWBLOCK}
SUB_FILES=	pkg-message

# backend type in { hosts, ipfw, pf }
SSHGUARDFW?=	hosts

.if ${SSHGUARDFW} == pf
PKGMSG_FWBLOCK="  To activate or configure PF see http://sshguard.sf.net/doc/setup/blockingpf.html"
.elif ${SSHGUARDFW} == ipfw
PKGMSG_FWBLOCK="  Verify that IPFW is active with \"ipfw show\"."
.elif ${SSHGUARDFW} == hosts
PKGMSG_FWBLOCK="  Sshguard is going to use /etc/hosts.allow. Please remember to touch /etc/hosts.allow\!"
.elif ${SSHGUARDFW} == ipfilter
PKGMSG_FWBLOCK="  Sshguard will use /etc/ipf.rules as ruleset."
.endif

.include <bsd.port.mk>
