# $FreeBSD$

PORTNAME=	zap
PORTVERSION=	0.6.4
CATEGORIES=	sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Maintain ZFS snapshots with cron

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Jehops

PLIST_FILES=	bin/zap
PORTDOCS=	README.org

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
