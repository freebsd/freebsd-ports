# Created by: John Polstra <jdp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pptpclient
PORTVERSION=	1.7.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

USES=		perl5

MAN8=		pptp.8

MAKE_ARGS=	DEBUG=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${PREFIX}/share/examples/pptpclient
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
