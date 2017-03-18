# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	pop3proxy
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://people.freebsd.org/~mbr/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 Proxy Server derived from UP IMAP Proxy

GNU_CONFIGURE=	yes
USES=		autoreconf ssl
USE_RC_SUBR=	pop3proxyd

post-patch:
	@${MV} ${WRKSRC}/aclocal.m4 ${WRKSRC}/acinclude.m4
	@${REINPLACE_CMD} 's/HAVE_LIBSSL/HAVE_LIBCRYPTO/' \
		${WRKSRC}/include/pop3proxy.h ${WRKSRC}/src/icc.c \
		${WRKSRC}/src/imapcommon.c ${WRKSRC}/src/main.c \
		${WRKSRC}/src/request.c

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} pop3proxystat pop3proxyd \
		${STAGEDIR}${PREFIX}/sbin)
	${INSTALL} -c ${WRKSRC}/pop3proxyd.conf \
		${STAGEDIR}${PREFIX}/etc/pop3proxyd.conf.sample

.include <bsd.port.mk>
