PORTNAME=	osrtspproxy
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/rtsp/RTSP%20Proxy%20Kit/${PORTVERSION}
DISTNAME=	${PORTNAME}_2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference implementation kit of an RTSP proxy

HAS_CONFIGURE=	yes

PLIST_FILES=	sbin/rtspproxy etc/rc.d/rtspproxy.sh.sample

do-install:
	(cd ${WRKSRC}/rtspproxy && ${INSTALL_PROGRAM} rtspproxy \
		${STAGEDIR}${PREFIX}/sbin)
	(cd ${FILESDIR} && ${INSTALL_SCRIPT} rtspproxy.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/rtspproxy.sh.sample)

.include <bsd.port.mk>
