# New ports collection makefile for:	bmon
# Date created:			21 Feb 2003
# Whom:				Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	bmon
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://people.suug.ch/~tgr/bmon/files/

MAINTAINER=	nistor@snickers.org
COMMENT=	Portable bandwidth monitor and rate estimator

LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

MAN1=		bmon.1
PLIST_FILES=	sbin/bmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/bmon.1 ${PREFIX}/man/man1/bmon.1

.include <bsd.port.mk>
