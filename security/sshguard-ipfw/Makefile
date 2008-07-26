# New ports collection makefile for:	sshguard-ipfw
# Date created:				17 May 2007
# Whom:					Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-ipfw

COMMENT=	Protect hosts from brute force attacks against ssh and other services using ipfw

CONFLICTS=	sshguard-1.* sshguard-ipfilter-1.* sshguard-pf-1.*

SSHGUARDFW=	ipfw
MASTERDIR=	${.CURDIR}/../sshguard

.include "${MASTERDIR}/Makefile"
