# New ports collection makefile for:	lookupd_ldap
# Date created:				3 July 2004
# Whom:					Michael Bushkov <bushman@rsu.ru>
#
# $FreeBSD$

PORTNAME=	lookupd_ldap
PORTVERSION=	0.1.a
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.rsu.ru/~bushman/lookupd/ldap/downloads/

MAINTAINER=	bushman@rsu.ru
COMMENT=	The LDAP plugin for the lookupd daemon

BUILD_DEPENDS=	${LOCALBASE}/sbin/lookupd:${PORTSDIR}/sysutils/lookupd

USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

PLIST_FILES=	lib/lkpd_ldap.so lib/lkpd_ldap.so.1

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
