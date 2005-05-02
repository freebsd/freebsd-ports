# New ports collection makefile for:    psmisc
# Date created:         10 March 1998
# Whom:                 rantapaa@uswest.net
#
# $FreeBSD$
#

PORTNAME=	psmisc
PORTVERSION=	17
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.uni-bremen.de/pub/mirrors/sunsite/system/status/ps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the Linux pstree, killall and pidof commands

CONFLICTS=	pstree-2.* \
		pidof-*

PLIST_FILES=	bin/killall \
		bin/pidof \
		bin/pstree

INSTALL_TARGET=	install-all
MAN1=		pidof.1 pstree.1 killall.1
WRKSRC=		${WRKDIR}/psmisc

.include <bsd.port.mk>
