# New ports collection makefile for:	py-syck
# Date created:			2 December 2004
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	syck
PORTVERSION=	0.55
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for Syck, a YAML parser and emitter

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:${PORTSDIR}/textproc/syck

SITELIBDIR=	%%PYTHON_SITELIBDIR%%/
PYFILES=	ypath.py ydump.py yaml2xml.py
PYFILES_=	${PYFILES:S/^/${SITELIBDIR}/}
PLIST_FILES=	${PYFILES_} ${PYFILES_:S/$/c/} ${PYFILES_:S/$/o/}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Syck
PYDISTUTILS_PKGVERSION=	1.0
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/python

.include <bsd.port.mk>
