# New ports collection makefile for: trac-customfieldadmin
# Date created:                      Jan 11 2008
# Whom:                              Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	customfieldadmin
PORTVERSION=	0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	Web interface to administer Trac ticket custom fields

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/TracWebAdmin-0.1.2dev-py${_PYTHON_VERSION}.egg:${PORTSDIR}/www/trac-webadmin

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.10
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
