# New ports collection makefile for:	TooFPy
# Date created:				31 March 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PORTNAME=	TooFPy
PORTVERSION=	0.3.7
CATEGORIES=	www python
MASTER_SITES=	http://simon.bofh.ms/~gb/ \
		LOCAL/beech
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	toolserver-snapshot.tar.gz

MAINTAINER=	frank@fenor.de
COMMENT=	Toolserver Framework for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/medusa:${PORTSDIR}/net/py-medusa \
		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
		${PYTHON_SITELIBDIR}/SOAPpy:${PORTSDIR}/net/py-soappy

BROKEN=		Installs files outside of localbase

WRKSRC=		${WRKDIR}/Toolserver-${PORTVERSION}
LATEST_LINK=	py-${PORTNAME}
USE_RC_SUBR=	toolserver
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Toolserver

OPTIONS=	PYCRYPTO "Use pycrypto (for RSA authentication)" off

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
OPTIONS+=	WSGIREF "WSGI compliant applications" off
.endif

.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto:${PORTSDIR}/security/py-pycrypto
.endif

.if defined(WITH_WSGIREF)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wsgiref:${PORTSDIR}/www/py-wsgiref
.endif

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
