# New ports collection makefile for:	imap-uw
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap-uw
PORTVERSION= 	4.7b
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/ \
		http://mirror.nucba.ac.jp/mirror/imap/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/
DISTNAME=	imap-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		imap-utils${EXTRACT_SUFX}

MAINTAINER=	imap-uw@freebsd.ady.ro

Y2K=		http://www.washington.edu/imap/IMAP-FAQs/FAQ-00002.html

PAMAUTH?=	yes
.if ${PAMAUTH} != "no"
ALL_TARGET=	bfp
.else
ALL_TARGET=	bsf
.endif
MAN8=		ipopd.8 imapd.8

SHLIBBASE=	c-client4
SHLIBMAJ=	7
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"
.if ${PAMAUTH} != "no"
	@${ECHO_MSG} ">> Building with PAM support"
	@${ECHO_MSG} ">> You can disable PAM support building with \"PAMAUTH=no\""
.endif

post-build:
	@(cd ${WRKDIR}/mlock; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)

do-install:
	${INSTALL_DATA} ${WRKSRC}/c-client/mail.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/c-client/rfc822.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/c-client/linkage.h ${PREFIX}/include
	${INSTALL} ${COPY} ${STRIP} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
		${WRKSRC}/c-client/${SHLIBNAME} ${PREFIX}/lib
	${LN} -sf ${SHLIBNAME} ${PREFIX}/lib/lib${SHLIBBASE}.so
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a \
		${PREFIX}/lib/lib${SHLIBBASE}.a
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g mail -m 2711 \
		${WRKDIR}/mlock/mlock ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PAMAUTH} != "no"
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
