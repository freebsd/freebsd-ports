# Ports collection Makefile for:	pamtester
# Date created:				24/05/2005
# Whom:					andy@fud.org.nz
#
# $FreeBSD$
#

PORTNAME=		pamtester
PORTVERSION=		0.1.2
CATEGORIES=		security
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A command line pam authentication tester

MAN1=			pamtester.1

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GMAKE=		yes

PLIST_FILES=		bin/pamtester

.include <bsd.port.mk>
