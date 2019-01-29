# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	pop3proxy
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://people.freebsd.org/~mbr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 Proxy Server derived from UP IMAP Proxy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	no upstream and does not properly initiate SSL/TLS connections
EXPIRATION_DATE=	2019-04-15

USES=		autoreconf ssl tar:tgz
USE_RC_SUBR=	pop3proxyd

GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/aclocal.m4 ${WRKSRC}/acinclude.m4
	@${REINPLACE_CMD} 's/HAVE_LIBSSL/HAVE_LIBCRYPTO/' \
		${WRKSRC}/include/pop3proxy.h ${WRKSRC}/src/icc.c \
		${WRKSRC}/src/imapcommon.c ${WRKSRC}/src/main.c \
		${WRKSRC}/src/request.c
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/Makefile.in

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} pop3proxystat pop3proxyd \
		${STAGEDIR}${PREFIX}/sbin)
	${INSTALL_DATA} ${WRKSRC}/pop3proxyd.conf \
		${STAGEDIR}${PREFIX}/etc/pop3proxyd.conf.sample

.include <bsd.port.mk>
