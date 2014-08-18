# Created by: sobomax
# $FreeBSD$

PORTNAME=	rtpproxy
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.rtpproxy.org/chrome/site/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance RTP proxy server for the SIP Express Router (SER)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-build:
	${SED} 's|%%PREFIX%%|${PREFIX}|g ; s|%%RC_SUBR%%|/etc/rc.subr|g' \
	    ${WRKSRC}/freebsd/rtpproxy.in > ${WRKDIR}/rtpproxy

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rtpproxy ${STAGEDIR}${PREFIX}/etc/rc.d/rtpproxy

.include <bsd.port.mk>
