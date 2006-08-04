# New ports collection makefile for:	linux-krb5-libs
# Date created:		2006-08-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	krb5-libs
PORTVERSION=	1.4
CATEGORIES=	security linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-3

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An authentication system, successor to Kerberos IV (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
AUTOMATIC_PLIST=yes
DESCR=	${.CURDIR}/../${PORTNAME:S/-libs//}/pkg-descr

.include <bsd.port.mk>
