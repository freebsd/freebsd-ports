# New ports collection makefile for:	linux-xerces-c2
# Date created:				7 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	xerces
PORTVERSION=	2.7.0
CATEGORIES=	textproc linux
MASTER_SITES=	http://ftp.belnet.be/packages/dries.ulyssis.org/fedora/fc4/i386/RPMS.dries/ \
		ftp://ftp.freshrpms.net/pub/dag/dries/fedora/fc4/i386/RPMS.dries/ \
		ftp://ftp.icm.edu.pl/vol/rzm4/linux-dag/dries/fedora/fc4/i386/RPMS.dries/
PKGNAMESUFFIX=	-c2
DISTNAME=	${PORTNAME}-c-${PORTVERSION}-1.2.fc4.rf

MAINTAINER=	ports@logvinov.com
COMMENT=	Validating XML parser from the Apache XML Project (linux version)

USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	i386 amd64
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
SRC_DISTFILES=
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
