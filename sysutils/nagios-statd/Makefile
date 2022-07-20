PORTNAME=	nagios-statd
PORTVERSION=	3.12
PORTREVISION=	2
CATEGORIES=	sysutils python net-mgmt
MASTER_SITES=	http://www.twoevils.org/files/netsaint_statd/

MAINTAINER=	jims@bluenotch.com
COMMENT=	Daemon/client to check remote host information for Nagios

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/share/doc/LICENSE

USES=		python shebangfix
SHEBANG_FILES=	bin/nagios-stat sbin/nagios-statd
USE_RC_SUBR=	nagiosstatd
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/nagios-stat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/nagios-statd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/share/man1/nagios-stat.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/man8/nagios-statd.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
