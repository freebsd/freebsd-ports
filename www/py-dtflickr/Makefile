# New ports collection makefile for:	py-dtflickr
# Date created:				19 August 2008
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	dtflickr
PORTVERSION=	1.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Spiffy Flickr API library using JSON

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python2.5"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.7:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
