# New ports collection makefile for:   clonehdd
# Date created:        21 August 2007
# Whom:            Anton Lysenok <bart@tapolsky.net.ua>
#
# $FreeBSD$
#

PORTNAME=	clonehdd
PORTVERSION=	2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bart@tapolsky.net.ua
COMMENT=	Tool for clone HDD on FreeBSD

USE_PERL5_RUN=	YES
PLIST_FILES=	sbin/clonehdd
NO_BUILD=	YES
MAN8=		clonehdd.8
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clonehdd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clonehdd.8 ${MAN8PREFIX}/man/man8
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
