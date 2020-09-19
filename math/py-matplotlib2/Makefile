# Created by: ijliao
# $FreeBSD$

PORTNAME=	matplotlib
DISTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users (legacy)

LICENSE=	PSFL

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libtcl86.so:lang/tcl86
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>=1.0.0:math/py-kiwisolver@${PY_FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>0:devel/py-backports.functools_lru_cache@${PY_FLAVOR}

USES=		compiler:c++11-lib gettext gnome pkgconfig python shebangfix uniquefiles:dirs
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		EXAMPLES \
			QT5AGGBACKEND TKAGGBACKEND
OPTIONS_DEFAULT=	TKAGGBACKEND
OPTIONS_SUB=		yes

QT5AGGBACKEND_DESC=	Qt5Agg backend support
QT5AGGBACKEND_USES=	display pyqt:5
QT5AGGBACKEND_USE=	PYQT=sip,widgets
QT5AGGBACKEND_VARS=	QT5AGG_BACKEND=True
QT5AGGBACKEND_VARS_OFF=	QT5AGG_BACKEND=False
TKAGGBACKEND_DESC=	TKAgg backend support
TKAGGBACKEND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKAGGBACKEND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKAGGBACKEND_USES=	display tk:run
TKAGGBACKEND_VARS=	TKAGG_BACKEND=True
TKAGGBACKEND_VARS_OFF=	TKAGG_BACKEND=False

PORTEXAMPLES=	*

post-extract:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} ${CHMOD} -x

post-patch:
	@${REINPLACE_CMD} -e 's|%%QT5AGG_BACKEND%%|${QT5AGG_BACKEND}|g' \
			 -e 's|%%TKAGG_BACKEND%%|${TKAGG_BACKEND}|g' \
		${WRKSRC}/setup.cfg

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/web_backend/jquery-ui-1.12.1
	cd ${WRKSRC}/lib/matplotlib/backends/web_backend/jquery-ui-1.12.1 && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib/backends/web_backend/jquery-ui-1.12.1
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib -name '*.so' \
		| ${XARGS} ${STRIP_CMD}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
