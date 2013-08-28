# Created by: John Polstra <jdp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pptpclient
PORTVERSION=	1.7.2
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

LICENSE=	GPLv2

USES=		perl5
MAKE_ARGS=	DEBUG=""

MAN8=		pptp.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${PREFIX}/share/examples/pptpclient
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
