# New ports collection makefile for:	txamqp
# Date created:		2009-07-04
# Whom:			Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	txamqp
PORTVERSION=	0.3
CATEGORIES=	net python
MASTER_SITES=	http://launchpadlibrarian.net/30388120/ \
		# http://launchpad.net/txamqp/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Twisted Python library for the AMQP messaging protocol

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/thrift/__init__.py:${PORTSDIR}/devel/py-thrift

USE_PYTHON=	2.5+
USE_PYDISTUTILS= easy_install
USE_TWISTED=	yes

WRKSRC=		${WRKDIR}/python-${PORTNAME}-${PORTVERSION}

PYDISTUTILS_PKGNAME=	txAMQP
PYDISTUTILS_PKGVERSION=	0.3
PLIST_SUB=	PORTNAME="${PORTNAME}"

# TODO: Install txAMQP examples.

# Don't try to install Twisted yourself, txAMQP. thx!
do-patch:
	@${REINPLACE_CMD} -e '/install_requires/s/^/#/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
