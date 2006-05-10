# New ports collection makefile for:	imapproxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	imapproxy
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.imapproxy.org/downloads/
PKGNAMEPREFIX=	up-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	A caching IMAP proxy server

GNU_CONFIGURE=	YES
USE_RC_SUBR=	imapproxyd.sh

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g" \
		-e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf.default
.if !exists(${PREFIX}/etc/imapproxyd.conf)
	${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
