# Created by: peter
# $FreeBSD: head/net/linux-f10-openldap/Makefile 362313 2014-07-20 11:59:59Z rene $

PORTNAME=	openldap
PORTVERSION=	2.4.12
PORTREVISION=	1
CATEGORIES=	net linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lightweight Directory Access Protocol libraries (Linux Fedora 10)

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=abad20bf-c1b4-11e3-a5ac-001b21614864

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../openldap24-server/pkg-descr

PLIST_FILES=	usr/lib/liblber-2.4.so.2 usr/lib/liblber-2.4.so.2.2.0 usr/lib/libldap-2.4.so.2 usr/lib/libldap-2.4.so.2.2.0 usr/lib/libldap_r-2.4.so.2 usr/lib/libldap_r-2.4.so.2.2.0 etc/openldap usr/share/man/man5/ldap.conf.5.gz usr/share/man/man5/ldif.5.gz
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README

# do not install any openldap configuration directories/files
post-extract:
	${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
