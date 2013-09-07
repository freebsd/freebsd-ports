# New ports collection makefile for:	snap
# Date created:				2007-05-07
# Whom:				Wu Chin-Hao <wchunhao@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	snap
DISTVERSION=	1.01
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cs.nctu.edu.tw/~wchunhao/ports/snap/

MAINTAINER=	wchunhao@cs.nctu.edu.tw
COMMENT=	Tools for periodic and manual management of UFS2 snapshots

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

MAN8=		snap.8

PLIST_FILES=	sbin/snap \
		etc/snap.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snap ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/snap.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/snap.conf ${PREFIX}/etc/

.include <bsd.port.mk>
