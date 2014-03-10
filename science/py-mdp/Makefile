# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}-toolkit/${PORTNAME}-toolkit/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular toolkit for Data Processing

LICENSE=	BSD

RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS_DEFINE=	LIBSVM PP SCIPY

LIBSVM_DESC=	Provide the LibSVMClassifier node
PP_DESC=	Provide the Parallel Python PPScheduler
SCIPY_DESC=	Instal SciPy versions of eigensolver, FFT and convolution

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBSVM}
RUN_DEPENDS+=	libsvm>2.91:${PORTSDIR}/science/libsvm \
		libsvm-python>2.91:${PORTSDIR}/science/libsvm-python
.endif

.if ${PORT_OPTIONS:MPP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pp>0:${PORTSDIR}/devel/py-pp
.endif

.if ${PORT_OPTIONS:MSCIPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}scipy>=0.5.2:${PORTSDIR}/science/py-scipy
.endif

.include <bsd.port.mk>
