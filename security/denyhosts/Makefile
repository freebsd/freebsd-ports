# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	denyhosts
PORTVERSION=	2.6
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	DenyHosts-${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Script to thwart ssh attacks

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USES=		shebangfix
env_OLD_CMD=	/bin/env
env_CMD=	${SETENV}
SHEBANG_LANG=	python env
SHEBANG_FILES=	plugins/test_deny.py \
		scripts/restricted_from_invalid.py \
		scripts/restricted_from_passwd.py

USE_RC_SUBR=	denyhosts
SUB_LIST+=	PYTHON=${PYTHON_CMD}
SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG.txt LICENSE.txt README.txt

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/daemon-control-dist \
		${WRKSRC}/denyhosts.cfg-dist \
		${WRKSRC}/setup.py

pre-install:
	@${FIND} ${WRKSRC} -type f \( -name \*.bak -o -name \*.orig \) -delete

post-install:
	${INSTALL_DATA} ${WRKSRC}/denyhosts.cfg-dist \
		${STAGEDIR}${PREFIX}/etc/denyhosts.conf-dist

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
