# New ports collection makefile for:	cclient
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cclient
PORTVERSION=	2001a
PORTEPOCH=	1
CATEGORIES=	mail devel
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/ \
		http://atreides.freenix.no/~anders/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/imap/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	imap-2001a
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	anders@FreeBSD.org

INSTALLS_SHLIB=	yes
ALL_TARGET=	bsf
.if defined(WITH_SSL)
MAKE_ARGS+=	SSLTYPE=unix
USE_OPENSSL=	yes
.endif

WRKSRC=		${WRKDIR}/imap-2001a
USE_REINPLACE=	yes

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
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"

HEADERS=	c-client.h dummy.h env.h env_unix.h fdstring.h flocksim.h \
		flstring.h fs.h ftl.h imap4r1.h linkage.c linkage.h mail.h \
		mbox.h mbx.h mh.h misc.h mmdf.h mtx.h mx.h netmsg.h news.h \
		newsrc.h nl.h nntp.h osdep.h phile.h pop3.h pseudo.h rfc822.h \
		smtp.h sslio.h tcp.h tcp_unix.h tenex.h unix.h utf8.h
PORTREV_H=	${WRKDIR}/portrevision.h

post-build:
	@${ECHO_CMD} "#define CCLIENT_PORTVERSION \"${PORTVERSION}\"" >${PORTREV_H}
.if defined(WITH_SSL)
	@${ECHO_CMD} "#define CCLIENT_SSLENABLED \"yes\"" >>${PORTREV_H}
.else
	@${ECHO_CMD} "#define CCLIENT_SSLENABLED \"no\"" >>${PORTREV_H}
.endif

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
	${INSTALL_DATA} ${PORTREV_H} ${PREFIX}/include/c-client
.if defined(WITH_SSL)
	@${ECHO} "================================================================================"
	@${ECHO} "Warning: You have chosen to include SSL support. Applications/ports that use"
	@${ECHO} "the cclient library but do not support SSL may stop working or have problems
	@${ECHO} "linking. Linking explicitly with ssl (-lssl -lcrypto) may or may not help."
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.post.mk>
