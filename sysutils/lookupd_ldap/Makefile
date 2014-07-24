# Created by: Michael Bushkov <bushman@rsu.ru>
# $FreeBSD$

PORTNAME=	lookupd_ldap
PORTVERSION=	0.1.a
PORTREVISION=	5
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.rsu.ru/~bushman/lookupd/ldap/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The LDAP plugin for the lookupd daemon

DEPRECATED=	Fails to build with new utmpx
EXPIRATION_DATE=	2014-07-23

BUILD_DEPENDS=	${LOCALBASE}/sbin/lookupd:${PORTSDIR}/sysutils/lookupd

USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

PLIST_FILES=	lib/lkpd_ldap.so lib/lkpd_ldap.so.1

.if !defined(WITH_OPENLDAP_VER) || ${WITH_OPENLDAP_VER} != "23"
EXTRA_PATCHES=	${FILESDIR}/extrapatch-config.h
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
