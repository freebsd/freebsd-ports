# $FreeBSD$

PORTNAME=	weboob
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Web Outside of Browsers

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PY_FUTURES} \
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

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PYDISTUTILS_BUILDARGS=	${CONFIGURE_ARGS}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} ${CONFIGURE_ARGS}

OPTIONS_DEFINE=		CLICOLOR MMS NSS QT5 RTMPDUMP
OPTIONS_DEFAULT=	CLICOLOR NSS QT5

CLICOLOR_DESC=		Color command line interface
CLICOLOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}

MMS_RUN_DEPENDS=	mimms:multimedia/mimms

NSS_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
			${PYTHON_PKGNAMEPREFIX}python-nss>0:security/py-python-nss@${PY_FLAVOR}

QT5_USES=		gmake pyqt:5
QT5_USE=		PYQT=core,gui,multimedia,multimediawidgets,sip,widgets
QT5_BINARY_ALIAS=	pyuic5-python${PYTHON_VER}=pyuic5-${PYTHON_VER}
QT5_CONFIGURE_ON=	--qt --xdg
QT5_CONFIGURE_OFF=	--no-qt --no-xdg

RTMPDUMP_RUN_DEPENDS=	rtmpdump:multimedia/rtmpdump

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|/etc/ssl/certs|${LOCALBASE}/etc/ssl|g' ${WRKSRC}/weboob/browser/nss.py

post-patch-QT5-off:
	@(cd ${WRKSRC}/man && ${RM} q*.1 weboob-config-qt.1)

.include <bsd.port.mk>
