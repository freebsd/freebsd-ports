# New ports collection makefile for:	imap-uw
# Version required:	4.1beta
# Date created:		9 Jan 1997
# Whom:			pst
#
# $Id: Makefile,v 1.5 1997/06/03 06:27:06 pst Exp $
#

DISTNAME=	imap-4.1.BETA
PKGNAME=	imap-uw-4.1b
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pst@freebsd.org

IGNOREFILES=	${DISTFILES}
ALL_TARGET=	bsf
MAN8=		ipopd.8 imapd.8

pre-build:
	@chmod 755 ${WRKSRC}/src/osdep/unix/drivers ${WRKSRC}/src/osdep/unix/mkauths

do-install:
	${INSTALL_DATA} ${WRKSRC}/c-client/libc-client.so.2.0 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a ${PREFIX}/lib/libc-client.a
	${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8
	
.include <bsd.port.mk>
