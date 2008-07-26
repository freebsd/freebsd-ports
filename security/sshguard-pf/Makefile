# New ports collection makefile for:	sshguard-pf
# Date created:				17 May 2007
# Whom:					Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-pf

COMMENT=	Protect hosts from brute force attacks against ssh and other services using pf

CONFLICTS=	sshguard-1.* sshguard-ipfilter-1.* sshguard-ipfw-1.*

SSHGUARDFW=	pf
MASTERDIR=	${.CURDIR}/../sshguard

.include "${MASTERDIR}/Makefile"
