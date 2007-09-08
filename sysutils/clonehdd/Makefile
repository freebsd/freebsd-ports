# New ports collection makefile for:   clonehdd
# Date created:        21 August 2007
# Whom:            Anton Lysenok <bart@tapolsky.net.ua>
#
# $FreeBSD$
#

PORTNAME=	clonehdd
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bart@tapolsky.net.ua
COMMENT=	Simple script for clone HDD on FreeBSD

USE_PERL5_RUN=	YES
PLIST_FILES=	sbin/clonehdd
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clonehdd ${PREFIX}/sbin

.include <bsd.port.mk>
