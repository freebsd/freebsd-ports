# New ports collection makefile for:	cclient
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	cclient
PORTVERSION=	4.7c
CATEGORIES=	mail devel
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/ \
		http://mirror.nucba.ac.jp/mirror/imap/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/
DISTNAME=	imap-${PORTVERSION}2
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kbyanc@posi.net

WRKSRC=		${WRKDIR}/imap-${PORTVERSION}

INSTALLS_SHLIB=	yes
PAMAUTH?=       yes
.if ${PAMAUTH} != "no"
ALL_TARGET=     bfp
.else
ALL_TARGET=     bsf
.endif

SHLIBBASE=	c-client4
SHLIBMAJ=	7
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=      lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"
.if ${PAMAUTH} != "no"
	@${ECHO_MSG} ">> Building with PAM support"
	@${ECHO_MSG} ">> You can disable PAM support building with \"PAMAUTH=no\""
.endif

HEADERS=	dummy.h env.h env_unix.h fdstring.h flstring.h fs.h ftl.h \
		imap4r1.h linkage.c linkage.h mail.h misc.h nl.h nntp.h \
		osdep.h pop3.h rfc822.h smtp.h tcp.h

do-install:
	${MKDIR} ${PREFIX}/include/c-client
.for f in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/c-client/${f} ${PREFIX}/include/c-client
.endfor
	${INSTALL} ${COPY} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
		${WRKSRC}/c-client/${SHLIBNAME} ${PREFIX}/lib
	${LN} -sf ${SHLIBNAME} ${PREFIX}/lib/lib${SHLIBBASE}.so
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a \
		${PREFIX}/lib/lib${SHLIBBASE}.a

post-install:
.if ${PAMAUTH} != "no"
	@${CAT} ${FILESDIR}/MESSAGE.PAM
.endif

.include <bsd.port.post.mk>
