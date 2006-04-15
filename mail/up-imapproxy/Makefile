# New ports collection makefile for:	imapproxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	imapproxy
PORTVERSION=	1.2.4
CATEGORIES=	mail
MASTER_SITES=	http://www.imapproxy.org/downloads/
PKGNAMEPREFIX=	up-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A caching IMAP proxy server

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
USE_RC_SUBR=	imapproxyd.sh

post-patch:
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g; s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-install:
	${INSTALL} -m 644 -c ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf.default
.	if !exists(${PREFIX}/etc/imapproxyd.conf)
		${INSTALL} -m 644 -c ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf
.	endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
