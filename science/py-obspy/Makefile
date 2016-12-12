# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	obspy
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python framework for seismological observatories

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9.0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}future>=0.12.4:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}suds>=0.4.0:net/py-suds \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python shebangfix zip
SHEBANG_FILES=	obspy/taup/tests/data/TauP_test_data/gendata.sh
USE_LDCONFIG=	yes
LDFLAGS+=	-shared
USE_PYTHON=	autoplist distutils

LDFLAGS+=	-shared

post-patch:
	${REINPLACE_CMD} -e "s#FC#${FC}#g" ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/obspy/lib/*.so

.include <bsd.port.mk>
