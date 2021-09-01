PORTNAME=	ioc
PORTVERSION=	0.8.2
CATEGORIES=	sysutils

MAINTAINER=	stefan@gronke.net
COMMENT=	Jail management CLI using libioc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		needs devel/py-libioc

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libioc>0:devel/py-libioc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>0:textproc/py-texttable@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	bsdci
USE_RC_SUBR=	ioc

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s#LIB_DIR =.*#LIB_DIR = \"${PREFIX}/lib/ioc\"#" ${WRKSRC}/bin/ioc

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ioc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/ioc ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ioc ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ioc_cli ${STAGEDIR}${PREFIX}/lib/ioc)

.include <bsd.port.mk>
