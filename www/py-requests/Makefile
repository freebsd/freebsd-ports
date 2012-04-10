# New ports collection makefile for: py-requests
# Date created:		2011-07-30
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	requests
PORTVERSION=	0.11.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Requests is an elegant and simple HTTP library for Python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.2:${PORTSDIR}/net/py-urllib3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gevent/__init__.py:${PORTSDIR}/devel/py-gevent \
		${PYTHON_SITELIBDIR}/certifi/__init__.py:${PORTSDIR}/security/py-certify \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.2:${PORTSDIR}/net/py-urllib3 \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.0.1:${PORTSDIR}/textproc/py-chardet

USE_PYTHON=	2.6-3.1
USE_PYDISTUTILS=	easy_install

REINPLACE_ARGS=	-i ""

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f \{\} \;
	@${FIND} ${WRKSRC} -type f -name '*.py' | \
		${XARGS} ${REINPLACE_CMD} 's|is_linux|is_freebsd|g'

.include <bsd.port.mk>
