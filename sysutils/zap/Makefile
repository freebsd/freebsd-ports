# $FreeBSD$

PORTNAME=	zap
PORTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Maintain ZFS snapshots with cron

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Jehops

PLIST_FILES=	bin/zap %%PORTDOCS%%%%DOCSDIR%%/README.org

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
