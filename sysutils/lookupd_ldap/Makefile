# New ports collection makefile for:	lookupd_ldap
# Date created:				3 July 2004
# Whom:					Michael Bushkov <bushman@rsu.ru>
#
# $FreeBSD$

PORTNAME=	lookupd_ldap
PORTVERSION=	0.1.a
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.rsu.ru/~bushman/lookupd/ldap/downloads/

MAINTAINER=	bushman@rsu.ru
COMMENT=	The LDAP plugin for the lookupd daemon

BUILD_DEPENDS=	${LOCALBASE}/sbin/lookupd:${PORTSDIR}/sysutils/lookupd

INSTALLS_SHLIB=	yes
USE_OPENLDAP=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
