# New ports collection makefile for:	imap-uw
# Version required:	4.2
# Date created:		9 Jan 1997
# Whom:			pst
#
# $Id: Makefile,v 1.18 1998/10/12 19:17:34 jseger Exp $
#

DISTNAME=	imap-4.2
PKGNAME=	imap-uw-4.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/old/ \
		http://www.freebsd.org/~steve/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	imap-uw@freebsd.ady.ro

ALL_TARGET=	bsf
MAN8=		ipopd.8 imapd.8

#pre-build:
#	@chmod 755 ${WRKSRC}/src/osdep/unix/drivers ${WRKSRC}/src/osdep/unix/mkauths

# this rule currently isn't called or used, because it's not sufficient to
# install just the .a file and mail.h, so we shouldn't install anything at all!
install-lib:
	${INSTALL_DATA} ${WRKSRC}/c-clinet/mail.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a ${PREFIX}/lib/libc-client.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/c-client/${SHLIB} ${PREFIX}/lib
	${LN} -sf ${SHLIB} ${PREFIX}/lib/libc-client.so
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
SHLIB=	libc-client.so.2
.else
SHLIB=	libc-client.so.2.1
.endif
