# New ports collection makefile for:	gotthard
# Date created:				11 Feb 2006
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	gotthard
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ssh through https proxy tunnel

MAN8=		gotthard.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotthard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gotthard.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/gotthard.conf ${PREFIX}/etc/gotthard.conf.sample
	[ -f ${PREFIX}/etc/gotthard.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/gotthard.conf ${PREFIX}/etc

.include <bsd.port.mk>
