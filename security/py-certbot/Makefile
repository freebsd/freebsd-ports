# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certbot
PORTVERSION=	${ACME_VERSION}
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Let's Encrypt client #'

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0.9.3:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.2.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.0.1:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}josepy>=1.1.0:security/py-josepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=1.3:devel/py-parsedatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
SUB_FILES=	500.certbot pkg-message
PLIST_FILES=	etc/periodic/weekly/500.certbot-${PYTHON_VER}
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${RUN_DEPENDS} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.2,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}repoze.sphinx.autointerface>0:devel/py-repoze.sphinx.autointerface@${PY_FLAVOR} \

MANPAGES_PLIST_FILES=	share/man/man1/certbot.1.gz \
			share/man/man7/certbot.7.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/certbot/compat/misc.py \
		${WRKSRC}/tests/cli_test.py

post-build-MANPAGES-on:
	# Avoid gmake / ${DO_MAKE_BUILD} -C ${WRKSRC}/docs man
	(cd ${WRKSRC}/docs && \
		sphinx-build-${PYTHON_VER} -N -b man . _build/man)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/500.certbot \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly/500.certbot-${PYTHON_VER}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/certbot.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/certbot.7 \
		${STAGEDIR}${PREFIX}/share/man/man7

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
