# Created by: John Polstra <jdp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pptpclient
DISTVERSION=	1.10.0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_RC_SUBR=	pptp
CFLAGS+=	-DUSER_PPP
MAKE_ARGS=	CC="${CC}" DEBUG="" OPTIMIZE="${CFLAGS}" PPPD=/usr/sbin/ppp

PLIST_FILES=	man/man8/pptp.8.gz sbin/pptp
PORTEXAMPLES=	README ppp.conf

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/ppp.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
