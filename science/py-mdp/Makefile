# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}-toolkit/${PORTNAME}-toolkit/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	Modular toolkit for Data Processing

LICENSE=	BSD

RUN_DEPENDS=	${PYNUMPY}

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS_DEFINE=	LIBSVM PP SCIPY

LIBSVM_DESC=	Provide the LibSVMClassifier node
PP_DESC=	Provide the Parallel Python PPScheduler
SCIPY_DESC=	Instal SciPy versions of eigensolver, FFT and convolution

NO_STAGE=	yes
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

#Python3 ready
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g:U}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info

.include <bsd.port.mk>
