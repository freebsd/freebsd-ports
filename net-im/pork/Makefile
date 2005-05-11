# New ports collection makefile for:   pork
# Date created:			04 Feb 2003
# Whom:				Bob Bomar <bob@bomar.us>
#
# $FreeBSD$
#

PORTNAME=		pork
PORTVERSION=		0.99.8.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=		krion@FreeBSD.org
COMMENT=		Console-based AIM client

USE_PERL5=		yes
USE_GETOPT_LONG=	yes
USE_OPENSSL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
