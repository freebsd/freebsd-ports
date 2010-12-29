# New ports collection makefile for:	pop3proxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	pop3proxy
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://people.freebsd.org/~mbr/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	POP3 Proxy Server derived from UP IMAP Proxy

GNU_CONFIGURE=	YES
USE_AUTOTOOLS=	autoconf213
USE_RC_SUBR=	pop3proxyd

SAMPLE_EXT=	sample

post-install:
	if [ ! -f ${PREFIX}/etc/pop3proxyd.conf ]; then \
		${INSTALL} -c ${WRKSRC}/pop3proxyd.conf ${PREFIX}/etc/pop3proxyd.conf ; \
	fi
	${INSTALL} -c ${WRKSRC}/pop3proxyd.conf ${PREFIX}/etc/pop3proxyd.conf.${SAMPLE_EXT} ;
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
