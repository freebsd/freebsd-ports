# New ports collection makefile for:	imap-uw
# Version required:	4.1beta
# Date created:		9 Jan 1997
# Whom:			pst
#
# $Id: Makefile,v 1.1.1.1 1997/01/10 02:38:35 pst Exp $
#

DISTNAME=	imap-4.1.BETA
PKGNAME=	imap-uw-4.1b
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pst@freebsd.org

ALL_TARGET=	fbd
MAN8=		ipopd.8 imapd.8

do-install:
	${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
		${WRKSRC}/imapd/imapd ${PREFIX}/libexec/imapd
	${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
		${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec/ipop2d
	${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
		${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec/ipop3d
	${INSTALL} -c -m ${MANMODE} -o ${MANOWN} -g ${MANGRP} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL} -c -m ${MANMODE} -o ${MANOWN} -g ${MANGRP} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8
	
.include <bsd.port.mk>
