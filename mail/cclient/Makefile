# New ports collection makefile for:	cclient
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cclient
PORTVERSION=	0104101757
CATEGORIES=	mail devel
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/ \
		http://www.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/imap/%SUBDIR%/ \
		http://mirror.nucba.ac.jp/mirror/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	imap-2001.BETA.SNAP-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	anders@fix.no

INSTALLS_SHLIB=	yes
ALL_TARGET=	bsf
.if defined(WITH_SSL)
MAKE_ARGS+=	SSLTYPE=unix
USE_OPENSSL=	yes
.endif

SHLIBBASE=	c-client4
SHLIBMAJ=	8
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

PREFIX_FIX_FILES=	Makefile src/osdep/unix/Makefile \
			src/osdep/unix/Makefile.gss

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-patch:
.for file in ${PREFIX_FIX_FILES}
	@${PERL} -pi -ne "s!/usr/local!${PREFIX}!g" ${WRKSRC}/${file}
.endfor

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"

HEADERS=	dummy.h env.h env_unix.h fdstring.h flstring.h fs.h ftl.h \
		imap4r1.h linkage.c linkage.h mail.h misc.h nl.h nntp.h \
		osdep.h pop3.h rfc822.h smtp.h tcp.h utf8.h c-client.h

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

.if defined(WITH_SSL)
post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Warning: You have chosen to include SSL support. Applications/ports that use"
	@${ECHO} "the cclient library but do not support SSL may stop working or have problems
	@${ECHO} "linking. Linking explicitly with ssl (-lssl -lcrypto) may or may not help."
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.post.mk>
