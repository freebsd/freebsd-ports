# New ports collection makefile for:	pidof
# Date created:		2005-05-01
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pidof
PORTVERSION=	20050501
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel
DISTNAME=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A tool which prints PID of given process name

CONFLICTS=	psmisc-1*

PLIST_FILES=	bin/pidof

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pidof ${PREFIX}/bin

.include <bsd.port.mk>
