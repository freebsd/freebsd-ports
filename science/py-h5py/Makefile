# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	A general-purpose Python interface to the HDF5 library

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

OPTIONS_DEFINE=	NEW_HDF5
NEW_HDF5_DESC=	Use port science/hdf5-18 instead of science/hdf5
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MNEW_HDF5}
LIB_DEPENDS=	hdf5:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS=	hdf5:${PORTSDIR}/science/hdf5
.endif

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
