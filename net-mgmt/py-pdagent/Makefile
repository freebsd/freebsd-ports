# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdagent
PORTVERSION=	1.6
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PagerDuty Agent software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		python:2.7 shebangfix
USE_PYTHON=	flavors
USE_RC_SUBR=	pdagentd
USE_GITHUB=	yes

GH_ACCOUNT=	PagerDuty
SHEBANG_FILES=	bin/*
NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}"
BINFILES=	pd-queue pd-send pdagentd.py

USERS=		pdagent
GROUPS=		pdagent

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib/pdagent|/var/db/pdagent| ; s|/etc|${ETCDIR}|' \
		${WRKSRC}/pdagent/confdirs.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR} ${STAGEDIR}/${ETCDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pdagent ${STAGEDIR}${PYTHON_SITELIBDIR})
	(cd ${WRKSRC}/bin ; ${INSTALL_SCRIPT} ${BINFILES} ${STAGEDIR}/${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/conf/pdagent.conf ${STAGEDIR}/${ETCDIR}/pdagent.conf.sample

.include <bsd.port.mk>
