# New ports collection makefile for:   OSSP uuid
# Date created:                12 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	1.0.0
CATEGORIES=	misc devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/${PORTNAME}/
PKGNAMEPREFIX=	ossp-

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	An ISO-C API and CLI for generating Universally Unique Identifiers

CONFLICTS=	e2fsprogs-*

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=		uuid-config.1 uuid.1
MAN3=		uuid.3

.include <bsd.port.mk>
