# New ports collection makefile for:	pymsn
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pymsn
PORTVERSION=	0.3.3
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MSN Connection library

LIB_PC_DEPENDS=	pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g} \
    		${PYTHON_SITELIBDIR}/ADNS.py:${PORTSDIR}/dns/py-adns \
		${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g} \
    		${PYTHON_SITELIBDIR}/ADNS.py:${PORTSDIR}/dns/py-adns \
		${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
