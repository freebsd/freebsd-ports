PORTNAME=	pynmsg
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for net/nmsg
WWW=		https://github.com/farsightsec/pynmsg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libnmsg.so:net/nmsg

USES=		pkgconfig python shebangfix uniquefiles:dirs
USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec
USE_PYTHON=	autoplist cython pep517

SHEBANG_FILES=	examples/*.py

PORTEXAMPLES=	*

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_nmsg*.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
