# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Collection of useful classes and functions for Django

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>=1.4.3<1.5:${PORTSDIR}/www/py-django14 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline>=1.2.16:${PORTSDIR}/www/py-django-pipeline
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>=1.4.3<1.5:${PORTSDIR}/www/py-django14 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline>=1.2.16:${PORTSDIR}/www/py-django-pipeline \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USES=		shebangfix
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Djblets

python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
SHEBANG_FILES=	contrib/internal/build-media.py

NO_STAGE=	yes
.include <bsd.port.mk>
