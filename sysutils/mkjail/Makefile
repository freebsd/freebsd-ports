PORTNAME=	mkjail
DISTVERSION=	0.0.4
CATEGORIES=	sysutils

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Fat jail creation script
WWW=		https://github.com/mkjail/mkjail

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
