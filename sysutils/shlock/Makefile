# New ports collection makefile for:	shlock
# Date created:		8 July 2002
# Whom:			dougb
#
# $FreeBSD$
#

PORTNAME=	shlock
PORTVERSION=	2.3.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=inn

DISTFILES=	inn-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Create lock files for use in shell scripts

HAS_CONFIGURE=	yes

MAN1=		shlock.1
PLIST_FILES=	bin/shlock

WRKSRC=		${WRKDIR}/inn-${PORTVERSION}

do-build:
	cd ${WRKSRC}/backends && ${MAKE} shlock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/backends/shlock ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/shlock.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
