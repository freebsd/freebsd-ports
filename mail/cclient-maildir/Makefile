# New ports collection makefile for:	c-client-maildir
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c-client-maildir
PORTVERSION=	4.7c
CATEGORIES=	mail devel
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/ \
		http://mirror.nucba.ac.jp/mirror/imap/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/
DISTNAME=	imap-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}2${EXTRACT_SUFX}

PATCH_SITES=	ftp://anonymous@highlander.fphil.uniba.sk/pub/pine/ \
		http://people.freebsd.org/~kbyanc/patches/
PATCHFILES=	pine-4.20-maildir_3.patch
PATCH_DIST_STRIP=-p1 + -p2 + -p2 + -p2 + -p2 + -p2 + -S

MAINTAINER=	kbyanc@FreeBSD.org

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

.if ${OSVERSION} < 410002 || ${OSVERSION} >= 500000 && ${OSVERSION} < 500011
FORBIDDEN=	"requires newer version of the patch utility"
.endif

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=      lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"
.if ${PAMAUTH} != "no"
	@${ECHO_MSG} ">> Building with PAM support"
	@${ECHO_MSG} ">> You can disable PAM support building with \"PAMAUTH=no\""
.endif

do-install:
	${MKDIR} ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/mail.h ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/rfc822.h ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/linkage.h ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/misc.h ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/smtp.h ${PREFIX}/include/c-client
	${INSTALL} ${COPY} ${STRIP} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
		${WRKSRC}/c-client/${SHLIBNAME} ${PREFIX}/lib
	${LN} -sf ${SHLIBNAME} ${PREFIX}/lib/lib${SHLIBBASE}.so
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a \
		${PREFIX}/lib/lib${SHLIBBASE}.a

post-install:
.if ${PAMAUTH} != "no"
	@${CAT} ${FILESDIR}/MESSAGE.PAM
.endif

.include <bsd.port.post.mk>
