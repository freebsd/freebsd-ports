# $FreeBSD$

PORTNAME=	check_ssl_cert
DISTVERSIONPREFIX=	v
DISTVERSION=	1.137.0
CATEGORIES=	net-mgmt

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Nagios/Icinga plugin for checking SSL/TLS certificates

LICENSE=	GPLv3

RUN_DEPENDS=	expect:lang/expect \
		curl:ftp/curl \
		p5-TimeDate>=0:devel/p5-TimeDate

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	matteocorti

PLIST_FILES=	libexec/nagios/check_ssl_cert \
		${MANPREFIX}/man/man1/check_ssl_cert.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ssl_cert ${STAGEDIR}${PREFIX}/libexec/nagios/
	${INSTALL_MAN} ${WRKSRC}/check_ssl_cert.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
