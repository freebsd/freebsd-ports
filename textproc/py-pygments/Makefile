# New ports collection makefile for:	py-pygments
# Date created:		2007-04-01
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pygments
PORTVERSION=	0.7.1
#PORTREVISION=	0
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A syntax highlighter written in Python

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PYPYGMENTS_EGG}

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYPYGMENTS_EGG=${PYPYGMENTS_EGG}

EASY_INSTALL_CMD=	easy_install-${PYTHON_VER}
PYPYGMENTS_EGG=	${DISTNAME}-py${PYTHON_VER}.egg

.if !defined(NOPORTDOCS)
DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
FIND_DOCS=	. -type f
MAN1=	pygmentize.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_DATA} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1/
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/build && ${FIND} ${FIND_DOCS} -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
.endif

.include <bsd.port.mk>
