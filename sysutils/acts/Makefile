PORTNAME=	acts
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils archivers

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Another Calendar-based Tarsnap Script

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tarsnap>=0:sysutils/tarsnap

USE_GITHUB=	yes
GH_ACCOUNT=	alexjurkiewicz

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acts ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/acts.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
