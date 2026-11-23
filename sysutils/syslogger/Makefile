PORTNAME=	syslogger
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://oav.net/projects/syslogger/

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Logger(1) like tool that sends file or pipe througth syslog
WWW=		https://oav.net/projects/syslogger/

PLIST_FILES=		bin/syslogger \
			share/man/man1/syslogger.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syslogger ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/syslogger.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
