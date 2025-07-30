PORTNAME=	check_ssl_cert
DISTVERSION=	2.94.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/matteocorti/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Nagios/Icinga plugin for checking SSL/TLS certificates
WWW=		https://matteocorti.github.io/check_ssl_cert/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	expect:lang/expect \
		curl:ftp/curl \
		p5-TimeDate>=0:devel/p5-TimeDate

USES=		tar:bz2

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	libexec/nagios/check_ssl_cert \
		${PREFIX}/share/man/man1/check_ssl_cert.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ssl_cert ${STAGEDIR}${PREFIX}/libexec/nagios/
	${INSTALL_MAN} ${WRKSRC}/check_ssl_cert.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
