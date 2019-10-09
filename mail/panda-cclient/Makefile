# Created by: Kelly Yancey <kbyanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cclient
PORTVERSION=	20130621
PORTREVISION=	1
CATEGORIES=	mail devel
PKGNAMEPREFIX=	panda-

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mark Crispin's C-client mail access routines forked from UW

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jonabbey
GH_PROJECT=	panda-imap
GH_TAGNAME=	7905901

CONFLICTS_INSTALL=	cclient-20*

OPTIONS_DEFINE=	SSL SSL_AND_PLAINTEXT IPV6 MBX_DEFAULT
OPTIONS_DEFAULT=	SSL
SSL_AND_PLAINTEXT_DESC=	Allow plain text passwords and SSL
MBX_DEFAULT_DESC=	Use MBX as default mailbox format

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USES+=		ssl
PKGMESSAGE=	pkg-message-ssl
.endif

USE_LDCONFIG=	yes
ALL_TARGET=	bsf
.if ! ${PORT_OPTIONS:MSSL}
MAKE_ARGS+=	SSLTYPE=none SSLDIR=${OPENSSLBASE}
.else
.if ${PORT_OPTIONS:MSSL_AND_PLAINTEXT}
MAKE_ARGS+=	SSLTYPE=unix SSLDIR=${OPENSSLDIR}
.else
MAKE_ARGS+=	SSLTYPE=unix.nopwd SSLDIR=${OPENSSLDIR}
.endif
.endif

MAKE_ARGS+=	EXTRACFLAGS="${CFLAGS}"

SHLIBBASE=	c-client4
SHLIBMAJ=	10
SHLIBNAME=	lib${SHLIBBASE}.so.${SHLIBMAJ}
MAKE_ENV+=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}
PLIST_SUB+=	SHLIBNAME=${SHLIBNAME} SHLIBBASE=${SHLIBBASE}

pre-configure:
.for file in Makefile src/osdep/unix/Makefile src/osdep/unix/Makefile.gss
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	${REINPLACE_CMD} -e "s:/etc/ssl/certs:${PREFIX}/certs:g; \
		s:/etc/ssl/private:${PREFIX}/certs:g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s:/etc/c-client.cf:${PREFIX}/etc/c-client.cf:" \
		${WRKSRC}/src/osdep/unix/env_unix.h
.if ${PORT_OPTIONS:MSSL}
	${REINPLACE_CMD} -e " \
		s:SSLINCLUDE=/usr/include/openssl SSLLIB=/usr/lib:SSLINCLUDE=${OPENSSLINC} SSLLIB=${OPENSSLLIB}: \
		" ${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MIPV6}
	${REINPLACE_CMD} -e "s|^IP=4|IP=6|" ${WRKSRC}/Makefile \
		${WRKSRC}/src/osdep/unix/Makefile
.endif
.if ${PORT_OPTIONS:MMBX_DEFAULT}
	${REINPLACE_CMD} -e "s|^CREATEPROTO=unixproto|CREATEPROTO=mbxproto|" \
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
.if ${PORT_OPTIONS:MSSL}
	@${ECHO_CMD} "#define CCLIENT_SSLENABLED \"yes\"" >>${PORTREV_H}
.else
	@${ECHO_CMD} "#define CCLIENT_SSLENABLED \"no\"" >>${PORTREV_H}
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/c-client
.for f in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/c-client/${f} ${STAGEDIR}${PREFIX}/include/c-client
.endfor
	${INSTALL_LIB} ${WRKSRC}/c-client/${SHLIBNAME} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${SHLIBNAME} ${STAGEDIR}${PREFIX}/lib/lib${SHLIBBASE}.so
	${INSTALL_DATA} ${WRKSRC}/c-client/c-client.a \
		${STAGEDIR}${PREFIX}/lib/lib${SHLIBBASE}.a
	${INSTALL_DATA} ${WRKSRC}/c-client/CFLAGS ${STAGEDIR}${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/LDFLAGS ${STAGEDIR}${PREFIX}/include/c-client
	${INSTALL_DATA} ${WRKSRC}/c-client/OSCFLAGS ${STAGEDIR}${PREFIX}/include/c-client
	${INSTALL_DATA} ${PORTREV_H} ${STAGEDIR}${PREFIX}/include/c-client

.include <bsd.port.mk>
