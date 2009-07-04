# New ports collection makefile for:	txamqp
# Date created:		2009-07-04
# Whom:			Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	txamqp
PORTVERSION=	0.2.1
CATEGORIES=	net python
MASTER_SITES=	http://launchpadlibrarian.net/20320545/ \
		# http://launchpad.net/txamqp/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Twisted Python library for the AMQP messaging protocol

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS= yes
USE_TWISTED=	yes

PYDISTUTILS_PKGNAME=	txAMQP
PYDISTUTILS_PKGVERSION=	0.2
PLIST_SUB=	PORTNAME="${PORTNAME}"

# TODO: Install AMQP spec files in a separate leaf port.
# TODO: Install txAMQP examples.
# TODO: Build and re-introduce Thrift runtime dependencies.

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: Thrift is not yet supported, Python bindings need fixed."
	@${ECHO_MSG}

.include <bsd.port.mk>
