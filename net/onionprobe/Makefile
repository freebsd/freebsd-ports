PORTNAME=	onionprobe
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Test and monitor the status of Tor Onion Services
WWW=		https://pypi.org/project/onionprobe

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=0:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		tor:security/tor

USES=		python shebangfix
USE_PYTHON=	autoplist cryptography distutils

NO_ARCH=	yes

SHEBANG_FILES=	packages/*.py \
		packages/onionprobe/*.py

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_PLIST_FILES=	share/man/man1/onionprobe.1.md.gz

post-patch:
	${REINPLACE_CMD} "s|%%ETCDIR%%|${ETCDIR}|g" \
	  ${WRKSRC}/docs/man/onionprobe.1.md \
	  ${WRKSRC}/packages/onionprobe/config.py
	${CP} ${FILESDIR}/extras-setup.py ${WRKSRC}/setup.py \
	  && ${REINPLACE_CMD} "s|%%NAME%%|${PORTNAME}|g; s|%%VERSION%%|${PORTVERSION}|g" ${WRKSRC}/setup.py

post-install-MANPAGES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1 \
	  && ${INSTALL_MAN} ${WRKSRC}/docs/man/onionprobe.1.md ${STAGEDIR}${PREFIX}/share/man/man1/.

.include <bsd.port.mk>
