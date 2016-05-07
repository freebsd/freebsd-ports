# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	bcfg2
PORTVERSION=	1.3.6
CATEGORIES=	sysutils python
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/bcfg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Configuration management system written in Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}daemon>=0:devel/py-daemon \
		${PYTHON_PKGNAMEPREFIX}gamin>=0:devel/py-gamin \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0:devel/py-lockfile \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml

OPTIONS_DEFINE=	CHEETAH GENSHI
CHEETAH_DESC=	Support Cheetah Templates
GENSHI_DESC=	Support Genshi Templates

USES=		python
USE_PYTHON=	distutils autoplist
USE_RC_SUBR=	bcfg2

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
PORTDOCS=	COPYRIGHT README

CHEETAH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=0:devel/py-cheetah
GENSHI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0:textproc/py-genshi

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -i '' -e 's|/etc/bcfg2.conf|${PREFIX}/etc/bcfg2.conf|g' ${WRKSRC}/src/sbin/* ${WRKSRC}/src/lib/Bcfg2/Options.py ${WRKSRC}/src/lib/Bcfg2/Server/models.py
	@${REINPLACE_CMD} -i '' -e 's|DEFAULT_INSTALL_PREFIX = ./usr.|DEFAULT_INSTALL_PREFIX = "${PREFIX}"|' ${WRKSRC}/src/lib/Bcfg2/Options.py
	@${REINPLACE_CMD} -i '' -e 's|/var/lock|/var/run|' ${WRKSRC}/src/lib/Bcfg2/Options.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
