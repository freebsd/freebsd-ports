# New ports collection makefile for:	net/linux-f10-openldap
# Date created:				2009-06-07
# Whom:					peter
#
# $FreeBSD$
#

PORTNAME=	openldap
PORTVERSION=	2.4.12
PORTREVISION=	1
CATEGORIES=	net linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lightweight Directory Access Protocol libraries (Linux Fedora 10)

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../openldap24-server/pkg-descr

PLIST_FILES=	usr/lib/liblber-2.4.so.2 usr/lib/liblber-2.4.so.2.2.0 usr/lib/libldap-2.4.so.2 usr/lib/libldap-2.4.so.2.2.0 usr/lib/libldap_r-2.4.so.2 usr/lib/libldap_r-2.4.so.2.2.0 etc/openldap
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README
MANPREFIX=	${PREFIX}/usr/share
MAN5=		ldap.conf.5 ldif.5
MANCOMPRESSED=	yes

# do not install any openldap configuration directories/files
post-extract:
	${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${LN} -sf ${LOCALBASE}/etc/openldap ${PREFIX}/etc

.include <bsd.port.mk>
