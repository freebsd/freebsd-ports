# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}-toolkit/${PORTNAME}-toolkit/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modular toolkit for Data Processing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	LIBSVM PP SCIPY

LIBSVM_DESC=	Provide the LibSVMClassifier node
PP_DESC=	Provide the Parallel Python PPScheduler
SCIPY_DESC=	Instal SciPy versions of eigensolver, FFT and convolution

LIBSVM_RUN_DEPENDS=	libsvm>2.91:science/libsvm \
			libsvm-python>2.91:science/libsvm-python
PP_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pp>0:devel/py-pp@${FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.5.2:science/py-scipy@${FLAVOR}

.include <bsd.port.mk>
