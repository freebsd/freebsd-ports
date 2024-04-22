PORTNAME=	portacl-rc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	security net

MAINTAINER=	tom@hur.st
COMMENT=	RC script for mac_portacl(4)
WWW=		https://github.com/Freaky/portacl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Freaky

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/portacl \
		share/man/man5/portacl.5.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portacl ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/portacl.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
