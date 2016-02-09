# Created by: John Polstra <jdp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pptpclient
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

LICENSE=	GPLv2+

USES=		perl5
USE_RC_SUBR=	pptp
MAKE_ARGS=	CC="${CC}" OPTIMIZE="${CFLAGS}" DEBUG="" \
		PPPD="/usr/sbin/ppp" IP="/usr/bin/true"
CFLAGS+=	-DUSER_PPP

PLIST_FILES=	sbin/pptp man/man8/pptp.8.gz
PORTEXAMPLES=	README ppp.conf

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
