# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedMail
PORTVERSION=	14.0.0
CATEGORIES=	mail devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Mail/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SMTP, IMAP, and POP protocol implementation with clients and servers

LICENSE=	MIT

USE_PYTHON=	distutils autoplist
USES=		python:2 tar:bzip2 twisted:names

.include <bsd.port.mk>
