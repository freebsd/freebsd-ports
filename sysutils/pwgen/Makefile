# New ports collection makefile for:	pwgen
# Date created:		22 July 2000
# Whom:			Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	pwgen
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tricknology.org/ports/

MAINTAINER=	oddbjorn@tricknology.org
COMMENT=	A simple password generator

USE_GETOPT_LONG=yes

WRKSRC=		${WRKDIR}/${PORTNAME}-1
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		pwgen.1
PLIST_FILES=	bin/pwgen

.include <bsd.port.mk>
