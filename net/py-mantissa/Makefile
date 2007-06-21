# New ports collection makefile for:	py-mantissa
# Date created:				29 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	mantissa
PORTVERSION=	0.4.1
CATEGORIES=	net www python
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mantissa-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Mantissa is an application server using the DivMod components

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/nevow/__init__.py:${PORTSDIR}/www/py-nevow \
		${PYTHON_SITELIBDIR}/axiom/__init__.py:${PORTSDIR}/databases/py-axiom \
		${PYTHON_SITELIBDIR}/vertex/__init__.py:${PORTSDIR}/net-p2p/py-vertex \
		${PYTHON_SITELIBDIR}/${PYPYTZ_EGG}:${PORTSDIR}/devel/py-pytz \
		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_SITELIBDIR}/twisted/mail/__init__.py:${PORTSDIR}/mail/py-twistedMail \
		${PYTHON_SITELIBDIR}/twisted/conch/__init__.py:${PORTSDIR}/security/py-twistedConch
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/nevow/__init__.py:${PORTSDIR}/www/py-nevow \
		${PYTHON_SITELIBDIR}/axiom/__init__.py:${PORTSDIR}/databases/py-axiom \
		${PYTHON_SITELIBDIR}/vertex/__init__.py:${PORTSDIR}/net-p2p/py-vertex \
		${PYTHON_SITELIBDIR}/${PYPYTZ_EGG}:${PORTSDIR}/devel/py-pytz \
		${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_SITELIBDIR}/twisted/mail/__init__.py:${PORTSDIR}/mail/py-twistedMail \
		${PYTHON_SITELIBDIR}/twisted/conch/__init__.py:${PORTSDIR}/security/py-twistedConch

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

PYPYTZ_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-pytz/Makefile -V PYPYTZ_EGG

.include <bsd.port.post.mk>
