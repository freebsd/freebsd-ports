PORTNAME=	recaptcha
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	PYPI/source/r/recaptcha-client
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-client-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Plugin for reCAPTCHA and reCAPTCHA Mailhide
WWW=		https://pypi.org/project/recaptcha-client/

DEPRECATED=	Python 2 code for the reCAPTCHA v1 API, which was shut down
BROKEN=		imports urllib2 (Python 2), and the reCAPTCHA v1 API it uses was shut down
EXPIRATION_DATE=	2026-12-01

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
