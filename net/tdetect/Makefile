# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	tdetect
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	PACKETSTORM/UNIX/loggers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for detecting traceroutes and reporting them via syslog

PLIST_FILES=	sbin/tdetect etc/rc.d/tdetect.sh
SUB_FILES=	pkg-message

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e 's/trdetect/tdetect/g' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's/LOG_AUTHPRIV/LOG_SECURITY/g' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tdetect ${PREFIX}/sbin/tdetect

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/tdetect.sh ]; then \
		${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/tdetect.sh startup file."; \
		${INSTALL_SCRIPT} -m 750 ${FILESDIR}/tdetect.sh ${PREFIX}/etc/rc.d/tdetect.sh; \
		${CAT} ${PKGMESSAGE}; \
	fi

.include <bsd.port.mk>
