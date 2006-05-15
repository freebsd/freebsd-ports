# New ports collection makefile for:	pkg-orphan
# Date created:				26 November 2005
# Whom:					Victor Semionov <semionov@mail.bg>
#
# $FreeBSD$
#

PORTNAME=	pkg-orphan
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	vsemionov@gmail.com
COMMENT=	A console utility for managing unreferenced FreeBSD packages

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		pkg-orphan.1

PLIST_FILES=	sbin/pkg-orphan

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-orphan.pl ${PREFIX}/sbin/pkg-orphan
	${INSTALL_MAN} ${WRKSRC}/pkg-orphan.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
