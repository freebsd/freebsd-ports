# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	sshguard
PORTVERSION=	1.6.2
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	SF/sshguard/sshguard/${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT?=	Protect hosts from brute force attacks against ssh and other services

LICENSE=	BSD2CLAUSE

CONFLICTS?=	sshguard-ipfilter-1.* sshguard-ipfw-1.* sshguard-pf-1.* sshguard-null-1.*

USES=		autoreconf tar:xz

PLIST_FILES=	sbin/sshguard man/man8/sshguard.8.gz

USE_RC_SUBR=	sshguard
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-firewall=${SSHGUARDFW}

SUB_LIST+=	PKGMSG_FWBLOCK=${PKGMSG_FWBLOCK}
SUB_FILES=	pkg-message

# backend type in { hosts, ipfw, null, pf }
SSHGUARDFW?=	hosts

.if ${SSHGUARDFW} == pf
PKGMSG_FWBLOCK="  To activate or configure PF see http://sshguard.sf.net/doc/setup/blockingpf.html"
.elif ${SSHGUARDFW} == ipfw
PKGMSG_FWBLOCK="  IPFW support has been rewritten. Sshguard will now add entries to table 22."
.elif ${SSHGUARDFW} == hosts
PKGMSG_FWBLOCK="  Sshguard is going to use /etc/hosts.allow. Please remember to touch /etc/hosts.allow\!"
.elif ${SSHGUARDFW} == ipfilter
PKGMSG_FWBLOCK="  Sshguard will use /etc/ipf.rules as ruleset."
.elif ${SSHGUARDFW} == null
PKGMSG_FWBLOCK="  Sshguard null backend requires you provide your own script with the \"-e\" argument."
.endif

.include <bsd.port.mk>
