PORTNAME=	tdetect
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	PACKETSTORM/UNIX/loggers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for detecting traceroutes and reporting them via syslog

PLIST_FILES=	sbin/tdetect etc/rc.d/tdetect.sh
SUB_FILES=	pkg-message

pre-configure:
	@${REINPLACE_CMD} -e 's/trdetect/tdetect/g' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's/LOG_AUTHPRIV/LOG_SECURITY/g' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tdetect ${STAGEDIR}${PREFIX}/sbin/tdetect
	${INSTALL_SCRIPT} -m 750 ${FILESDIR}/tdetect.sh ${STAGEDIR}${PREFIX}/etc/rc.d/tdetect.sh

.include <bsd.port.mk>
