PORTNAME=	bpytop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.68
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Linux/OSX/FreeBSD resource monitor
WWW=		https://github.com/aristocratos/bpytop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	aristocratos

SHEBANG_FILES=	bpytop.py

NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bpytop.py ${STAGEDIR}${PREFIX}/bin/bpytop
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} themes ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
