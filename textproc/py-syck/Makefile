# New ports collection makefile for:	py-syck
# Date created:			2 December 2004
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	syck
PORTVERSION=	0.45
CATEGORIES=	textproc devel
MASTER_SITES=	http://rubyforge.org/frs/download.php/1371/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Python binding for Syck, a YAML parser and emitter

BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:${PORTSDIR}/textproc/syck

SITELIBDIR=	%%PYTHON_SITELIBDIR%%/
PYFILES=	ypath.py ydump.py yaml2xml.py
PYFILES_=	${PYFILES:S/^/${SITELIBDIR}/}
PLIST_FILES=	${PYFILES_} ${PYFILES_:S/$/c/} ${PYFILES_:S/$/o/}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/python

.include <bsd.port.mk>
