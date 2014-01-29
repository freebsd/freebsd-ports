# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	txamqp
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://launchpadlibrarian.net/30388120/ \
		# http://launchpad.net/txamqp/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	horus.li@gmail.com
COMMENT=	Twisted Python library for the AMQP messaging protocol

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}thrift>0:${PORTSDIR}/devel/py-thrift

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
USES=		twisted

WRKSRC=		${WRKDIR}/python-${PORTNAME}-${PORTVERSION}

PYDISTUTILS_PKGNAME=	txAMQP
PYDISTUTILS_PKGVERSION=	0.3
PLIST_SUB=		PORTNAME="${PORTNAME}"

# TODO: Install txAMQP examples.

# Don't try to install Twisted yourself, txAMQP. thx!
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/install_requires/s/^/#/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
