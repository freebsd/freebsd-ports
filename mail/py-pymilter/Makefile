PORTNAME=	pymilter
DISTVERSION=	1.0.6
PORTREVISION=	1
DISTVERSIONPREFIX=	${GH_PROJECT}-
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Python interface to Sendmail milter API
WWW=		https://www.pymilter.org/ \
		https://github.com/sdgathman/pymilter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	python

USE_GITHUB=	yes
GH_ACCOUNT=	sdgathman

USE_PYTHON=	distutils autoplist flavors

OPTIONS_SINGLE=	MILTER
OPTIONS_SINGLE_MILTER=	LIBMILTER BASE
OPTIONS_DEFAULT=	LIBMILTER

LIBMILTER_DESC=	Link against libmilter from mail/libmilter
LIBMILTER_VARS=	WITH_MILTER_PORT=yes
LIBMILTER_VARS_OFF=	WITH_MILTER_BASE=

BASE_DESC=	Link against libmilter from base Sendmail
BASE_VARS=	WITH_MILTER_BASE=yes
BASE_VARS_OFF=	WITH_MILTER_PORT=

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/milter*.so

.include <bsd.port.post.mk>
