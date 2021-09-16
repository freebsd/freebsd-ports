PORTNAME=	mkjail
DISTVERSION=	0.0.3
CATEGORIES=	sysutils

MAINTAINER=	fuz@fuz.su
COMMENT=	Fat jail creation script

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
		cd ${WRKSRC}/src && ${CP} -a bin share etc ${STAGEDIR}${PREFIX}

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
