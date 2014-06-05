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
USE_AUTOTOOLS=	autoconf213
USE_RC_SUBR=	pop3proxyd

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} pop3proxystat pop3proxyd \
		${STAGEDIR}${PREFIX}/sbin)
	${INSTALL} -c ${WRKSRC}/pop3proxyd.conf \
		${STAGEDIR}${PREFIX}/etc/pop3proxyd.conf.sample

.include <bsd.port.mk>
