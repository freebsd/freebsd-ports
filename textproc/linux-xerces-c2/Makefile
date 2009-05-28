# New ports collection makefile for:	linux-xerces-c2
# Date created:				7 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	xerces
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	textproc linux
MASTER_SITES=	http://ftp.belnet.be/packages/dries.ulyssis.org/fedora/fc4/i386/RPMS.dries/ \
		ftp://ftp.freshrpms.net/pub/dag/dries/fedora/fc4/i386/RPMS.dries/ \
		http://mirrors.ircam.fr/pub/dag/dries/packages/xerces-c/xerces-c/fc4-i386/
PKGNAMESUFFIX=	-c2
DISTNAME=	${PORTNAME}-c-${PORTVERSION}-1.fc4.rf

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project (linux version)

USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	i386 amd64
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
SRC_DISTFILES=
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
