# Created by: Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
# $FreeBSD$

PORTNAME=	osrtspproxy
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/rtsp/RTSP%20Proxy%20Kit/${PORTVERSION}
DISTNAME=	${PORTNAME}_2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The RTSP Proxy Kit - A reference implementation of an RTSP proxy

HAS_CONFIGURE=	yes

PLIST_FILES=	sbin/rtspproxy etc/rc.d/rtspproxy.sh.sample

post-patch:
	@${REINPLACE_CMD} -e \
		'/CC=/s|^|#| ; \
		 /CXX=/s|^|#| ; \
		 /LD=/s|^|#| ; \
		 s|-I/usr/local/include|| ; \
		 s|-L/usr/local/lib||' ${WRKSRC}/configure

do-install:
	(cd ${WRKSRC}/rtspproxy && ${INSTALL_PROGRAM} rtspproxy \
		${STAGEDIR}${PREFIX}/sbin)
	(cd ${FILESDIR} && ${INSTALL_SCRIPT} rtspproxy.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/rtspproxy.sh.sample)

.include <bsd.port.mk>
