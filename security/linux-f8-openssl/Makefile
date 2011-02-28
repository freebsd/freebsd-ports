# New ports collection makefile for:	security/linux-f8-openssl
# Date created:				2008-04-09
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.9.8b
PORTREVISION=	1
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The OpenSSL toolkit (Linux Fedora 8)

CONFLICTS=	linux-openssl-[0-9]* linux-f10-openssl-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	17.fc8
BRANDELF_FILES=	usr/bin/openssl
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
