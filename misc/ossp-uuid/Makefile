# New ports collection makefile for:   OSSP uuid
# Date created:                12 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	1.0.1
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	fuyuki@hadaly.org
COMMENT=	An ISO-C API and CLI for generating Universally Unique Identifiers

CONFLICTS=	e2fsprogs-[0-9]*

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=		uuid-config.1 uuid.1
MAN3=		uuid.3

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.mk>
