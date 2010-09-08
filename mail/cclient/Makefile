# New ports collection makefile for:	cclient
# Date created:				2 July 2000
# Whom:					Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cclient
PORTVERSION=	2007e
PORTEPOCH=	1
CATEGORIES=	mail devel ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		http://atreides.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	imap-${PORTVERSION}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Mark Crispin's C-client mail access routines

OPTIONS=	SSL "Compile with SSL support" on \
		SSL_AND_PLAINTEXT "Allow plain text passwords and SSL" off \
		IPV6 "Support IPv6" on \
		MBX_DEFAULT "Use MBX as default mailbox format" off

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ! defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

USE_LDCONFIG=	yes
ALL_TARGET=	bsf
.if defined(WITHOUT_SSL)
MAKE_ARGS+=	SSLTYPE=none SSLDIR=${OPENSSLBASE}
.else
.if defined(WITH_SSL_AND_PLAINTEXT)
MAKE_ARGS+=	SSLTYPE=unix SSLDIR=${OPENSSLDIR}
.else
MAKE_ARGS+=	SSLTYPE=unix.nopwd SSLDIR=${OPENSSLDIR}
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

SHLIBBASE=	c-client4
SHLIBMAJ=	9
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV+=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

post-patch:
.for file in Makefile src/osdep/unix/Makefile src/osdep/unix/Makefile.gss
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s:/etc/ssl/certs:${PREFIX}/certs:g; \
		s:/etc/ssl/private:${PREFIX}/certs:g" ${WRKSRC}/Makefile
.if ! defined(WITHOUT_SSL)
	@${REINPLACE_CMD} -e " \
		s:SSLINCLUDE=/usr/include/openssl SSLLIB=/usr/lib:SSLINCLUDE=${OPENSSLINC} SSLLIB=${OPENSSLLIB}: \
		" ${WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_IPV6)
	@${REINPLACE_CMD} -e "s|^IP=4|IP=6|" ${WRKSRC}/Makefile \
		${WRKSRC}/src/osdep/unix/Makefile
.endif
.if defined(WITH_MBX_DEFAULT)
	@${REINPLACE_CMD} -e "s|^CREATEPROTO=unixproto|CREATEPROTO=mbxproto|" \
		${WRKSRC}/src/osdep/unix/Makefile
.endif

post-configure:
	@${ECHO_MSG} ">> The c-client shared library will be named ${SHLIBNAME}"

HEADERS=	c-client.h dummy.h env.h env_unix.h fdstring.h flockcyg.h \
		flocksim.h flstring.h fs.h ftl.h imap4r1.h linkage.c linkage.h \
		mail.h misc.h netmsg.h newsrc.h nl.h nntp.h osdep.h pseudo.h \
		rfc822.h smtp.h sslio.h tcp.h tcp_unix.h unix.h utf8.h \
		utf8aux.h
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
	${INSTALL_DATA} ${WRKSRC}/c-client/CFLAGS ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/LDFLAGS ${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/OSCFLAGS ${PREFIX}/include/c-client

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
