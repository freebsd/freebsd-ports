# New ports collection makefile for:	imap-uw
# Version required:	4.4
# Date created:		9 Jan 1997
# Whom:			pst
#
# $Id: Makefile,v 1.24 1998/12/24 18:26:21 jseger Exp $
#

DISTNAME=	imap-4.4
PKGNAME=	imap-uw-4.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	imap-uw@freebsd.ady.ro

Y2K=		http://www.washington.edu/imap/IMAP-FAQs/FAQ-00002.html

ALL_TARGET=	bsf
MAN8=		ipopd.8 imapd.8

SHLIBBASE=	c-client4
SHLIBMAJ=	4
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/c-client/mail.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/c-client/rfc822.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/c-client/linkage.h ${PREFIX}/include
	${INSTALL} ${COPY} ${STRIP} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
		${WRKSRC}/c-client/${SHLIBNAME} ${PREFIX}/lib
	${LN} -sf ${SHLIBNAME} ${PREFIX}/lib/lib${SHLIBBASE}.so
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

.include <bsd.port.post.mk>
