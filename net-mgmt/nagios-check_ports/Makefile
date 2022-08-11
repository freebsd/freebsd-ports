PORTNAME=	check_ports
PORTVERSION=	0.7.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ryanrfrederick@gmail.com
COMMENT=	Monitor FreeBSD ports for updates or vulnerabilities

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rfrederick

NO_BUILD=	yes

PLIST_FILES=	libexec/nagios/check_ports

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ports ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
