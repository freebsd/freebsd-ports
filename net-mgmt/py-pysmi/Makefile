# Created by: John W. O'Brien <john@saltant.com>
# $FreeBSD$

PORTNAME=	pysmi
PORTVERSION=	0.0.6
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP \
		SF/pysmi/pysmi/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	SNMP/SMI MIB parsing in Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply

NO_ARCH=	yes
USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	scripts/mibdump.py

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

BASEDOCS=	CHANGES.txt README.txt TODO.txt

post-patch:
	${CP} ${FILESDIR}/tests__init__.py ${WRKSRC}/tests/__init__.py
	${MV} ${WRKSRC}/tests ${WRKSRC}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BASEDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
