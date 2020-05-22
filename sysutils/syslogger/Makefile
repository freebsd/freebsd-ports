# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	syslogger
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://oav.net/projects/syslogger/

MAINTAINER=	kiwi@oav.net
COMMENT=	Logger(1) like tool that sends file or pipe througth syslog

PLIST_FILES=		bin/syslogger

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syslogger ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
