# New ports collection makefile for:  rdesktop
# Date created:               13 December 2000
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	rdesktop
PORTVERSION=	1.4.1
PORTREVISION?=	0
CATEGORIES=	net comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	RDP client for Windows NT/2000/2003 Terminal Server

USE_XLIB=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
DOCS=		doc/AUTHORS doc/TODO doc/*.txt
MAN1=		rdesktop.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdesktop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/rdesktop.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${DATADIR}/keymaps
	${INSTALL_DATA} ${WRKSRC}/keymaps/* ${DATADIR}/keymaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
