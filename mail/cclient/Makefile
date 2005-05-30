# New ports collection makefile for:	cclient
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cclient
PORTVERSION=	2004d
PORTEPOCH=	1
CATEGORIES=	mail devel ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		http://atreides.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	imap-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Mark Crispin's C-client mail access routines

INSTALLS_SHLIB=	yes
ALL_TARGET=	bsf
.if defined(WITHOUT_SSL)
MAKE_ARGS+=	SSLTYPE=none
.else
USE_OPENSSL=	yes
.if defined(WITH_SSL_AND_PLAINTEXT)
MAKE_ARGS+=	SSLTYPE=unix
.else
MAKE_ARGS+=	SSLTYPE=unix.nopwd
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_REINPLACE=	yes

SHLIBBASE=	c-client4
SHLIBMAJ=	8
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}.0
.endif

post-patch:
.for file in Makefile src/osdep/unix/Makefile src/osdep/unix/Makefile.gss
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s:/etc/ssl/certs:${PREFIX}/certs:g; \
		s:/etc/ssl/private:${PREFIX}/certs:g" ${WRKSRC}/Makefile
.if !defined(WITHOUT_IPV6)
	@${REINPLACE_CMD} -e "s|^IP=4|IP=6|" ${WRKSRC}/Makefile \
		${WRKSRC}/src/osdep/unix/Makefile
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"

HEADERS=	c-client.h dummy.h env.h env_unix.h fdstring.h flstring.h \
		fs.h ftl.h imap4r1.h linkage.c linkage.h mail.h mbx.h mh.h \
		misc.h mx.h netmsg.h newsrc.h nl.h nntp.h osdep.h pseudo.h \
		rfc822.h smtp.h sslio.h tcp.h tcp_unix.h unix.h utf8.h
PORTREV_H=	${WRKDIR}/portrevision.h

post-build:
	@${ECHO_CMD} "#define CCLIENT_PORTVERSION \"${PORTVERSION}\"" >${PORTREV_H}
.if !defined(WITHOUT_SSL)
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
.if !defined(WITHOUT_SSL)
	@${ECHO} "================================================================================"
	@${ECHO} "Warning: You have chosen to include SSL support. Applications/ports that use"
	@${ECHO} "the cclient library but do not support SSL may stop working or have problems"
	@${ECHO} "linking. Linking them explicitly with ssl (-lssl -lcrypto) may or may not help."
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.post.mk>
