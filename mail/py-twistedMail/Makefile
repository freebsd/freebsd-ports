# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedMail
PORTVERSION=	15.2.1
CATEGORIES=	mail devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Mail/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SMTP, IMAP, and POP protocol implementation with clients and servers

LICENSE=	MIT

DEPRECATED=	Use devel/py-twisted instead
EXPIRATION_DATE=2017-09-30

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2 twisted:names

.include <bsd.port.mk>
