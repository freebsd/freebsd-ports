# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedMail
PORTVERSION=	13.2.0
CATEGORIES=	mail devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Mail/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SMTP, IMAP, and POP protocol implementation with clients and servers

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}twistedNames>=${PORTVERSION}:${PORTSDIR}/dns/py-twistedNames
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}

NO_STAGE=	yes
.include <bsd.port.mk>
