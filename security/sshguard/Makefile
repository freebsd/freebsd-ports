# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	sshguard
PORTVERSION=	1.7.1
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	SF/sshguard/sshguard/${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT?=	Protect hosts from brute force attacks against ssh and other services

SSHGUARDFW?=	none

# If SSHGUARDFW is not set by a slave port, then we only use the
# following which makes this a metaport to choose a backend
.if ${SSHGUARDFW} == none
NO_BUILD=YES
NO_INSTALL=YES
NO_ARCH=YES

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	IPFW NULL PF
OPTIONS_DEFAULT=	IPFW

IPFW_DESC=	IPFW firewall backend
NULL_DESC=	null firewall backend (detection only)
PF_DESC=	pf firewall backend

IPFW_RUN_DEPENDS=	sshguard-ipfw>0:security/sshguard-ipfw
NULL_RUN_DEPENDS=	sshguard-null>0:security/sshguard-null
PF_RUN_DEPENDS=		sshguard-pf>0:security/sshguard-pf

.include <bsd.port.options.mk>

# The remaining settings are used by the slave ports
.else

LICENSE=	BSD2CLAUSE

USES=		autoreconf

PLIST_FILES=	libexec/sshg-fw libexec/sshg-logtail libexec/sshg-parser \
		sbin/sshguard man/man8/sshguard.8.gz

USE_RC_SUBR=	sshguard
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-firewall=${SSHGUARDFW}

SUB_LIST+=	PKGMSG_FWBLOCK=${PKGMSG_FWBLOCK}
SUB_FILES=	pkg-message
.endif

.if ${SSHGUARDFW} == pf
PKGMSG_FWBLOCK="  To activate or configure PF see http://www.sshguard.net/docs/setup/firewall/pf/"
.elif ${SSHGUARDFW} == ipfw
PKGMSG_FWBLOCK="  IPFW support has been rewritten. Sshguard will now add entries to table 22."
.elif ${SSHGUARDFW} == null
PKGMSG_FWBLOCK="  Sshguard null backend does detection only. It does not take action."
.endif

.include <bsd.port.mk>
