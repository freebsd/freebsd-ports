# New ports collection makefile for:	digest
# Date created:				2001-03-09
# Whom:					trevor
#
# $NetBSD: Makefile,v 1.37 2003/07/17 22:52:13 grant Exp $
# $FreeBSD$
#

PORTNAME?=	digest
PORTVERSION?=	20050323
PORTREVISION=	1
CATEGORIES?=	security sysutils
MASTER_SITES?=	http://highsecure.ru/

MAINTAINER?=	vsevolod@FreeBSD.org
COMMENT?=	Message digest wrapper utility

CONFLICTS?=	nss-[0-9]* emboss-[0-9]* qmail-ldap2-*

GNU_CONFIGURE=	yes

MAN1?=		${PORTNAME}.1

PLIST_FILES?=	bin/${PORTNAME}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

test: build
	@${ECHO_MSG} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} DIGESTCMD=${PORTNAME} ${SH} ./regress.sh
	@${ECHO_MSG} "All tests completed"

.include <bsd.port.post.mk>
