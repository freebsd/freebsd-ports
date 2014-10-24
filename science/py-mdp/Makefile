# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}-toolkit/${PORTNAME}-toolkit/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Modular toolkit for Data Processing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS_DEFINE=	LIBSVM PP SCIPY

LIBSVM_DESC=	Provide the LibSVMClassifier node
PP_DESC=	Provide the Parallel Python PPScheduler
SCIPY_DESC=	Instal SciPy versions of eigensolver, FFT and convolution

LIBSVM_RUN_DEPENDS=	libsvm>2.91:${PORTSDIR}/science/libsvm \
			libsvm-python>2.91:${PORTSDIR}/science/libsvm-python
PP_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pp>0:${PORTSDIR}/devel/py-pp
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.5.2:${PORTSDIR}/science/py-scipy

.include <bsd.port.mk>
