# New ports collection makefile for:	bmon
# Date created:			21 Feb 2003
# Whom:				Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	bmon
PORTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	http://people.suug.ch/~tgr/bmon/files/

MAINTAINER=	nistor@snickers.org
COMMENT=	"BMON - Portable bandwidth monitor and rate estimator"

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

MAN1=		bmon.1
PLIST_FILES=	sbin/bmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/bmon.1 ${PREFIX}/man/man1/bmon.1

.include <bsd.port.mk>
