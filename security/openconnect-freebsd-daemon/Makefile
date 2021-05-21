PORTNAME=	openconnect-freebsd-daemon
DISTVERSION=	1.1.0
CATEGORIES=	security net-vpn

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	OpenConnect service daemon for FreeBSD rc(8)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	openconnect:security/openconnect

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

NO_ARCH=	yes

PLIST_FILES=	etc/rc.d/openconnect \
		etc/rc.d/openconnect_services
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
