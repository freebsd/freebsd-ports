# New ports collection makefile for:	pv
# Date created:		04 May 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	pv
PORTVERSION=	0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dragon.roe.ch/mirrors/distfiles/pv/
MASTER_SITE_SUBDIR=	pipeviewer

MAINTAINER=	daniel@roe.ch
COMMENT=	A pipe throughput monitor

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		pv.1
INFO=		pv

PLIST_FILES=	bin/pv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${PREFIX}/man/man1/pv.1
	${INSTALL_MAN} ${WRKSRC}/doc/pv.info ${PREFIX}/info
	install-info ${PREFIX}/info/pv.info ${PREFIX}/info/dir

.include <bsd.port.mk>
