# Ports collection makefile for:	h5py
# Date created:			Jun 22, 2009
# Whom:				TAOKA Fumiyoshi
#
# $FreeBSD$
#

PORTNAME=	h5py
PORTVERSION=	1.2.1
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	A general-purpose Python interface to the HDF5 library

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
