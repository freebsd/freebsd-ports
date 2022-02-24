PORTNAME=	woob
PORTVERSION=	3.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Web Outside of Browsers

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}html2text>=3.200:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyExecJS>=0:devel/py-PyExecJS@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		wget:ftp/wget \
		gpg2:security/gnupg

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PYDISTUTILS_BUILDARGS=	${CONFIGURE_ARGS}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} ${CONFIGURE_ARGS}

OPTIONS_DEFINE=		CLICOLOR NSS RTMPDUMP
OPTIONS_DEFAULT=	CLICOLOR NSS

CLICOLOR_DESC=		Color command line interface
CLICOLOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}

NSS_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
			${PYTHON_PKGNAMEPREFIX}python-nss>0:security/py-python-nss@${PY_FLAVOR}

RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|/etc/ssl/certs|${LOCALBASE}/etc/ssl|g' ${WRKSRC}/woob/browser/nss.py

.include <bsd.port.mk>
