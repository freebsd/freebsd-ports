PORTNAME=	pptpclient
DISTVERSION=	1.10.0
CATEGORIES=	net net-vpn
MASTER_SITES=	SF/pptpclient/pptp/pptp-${PORTVERSION}
DISTNAME=	pptp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5

CFLAGS+=	-DUSER_PPP
MAKE_ARGS=	CC="${CC}" DEBUG="" OPTIMIZE="${CFLAGS}" PPPD=/usr/sbin/ppp
USE_RC_SUBR=	pptp

PLIST_FILES=	sbin/pptp share/man/man8/pptp.8.gz
PORTEXAMPLES=	README ppp.conf

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/ppp.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
