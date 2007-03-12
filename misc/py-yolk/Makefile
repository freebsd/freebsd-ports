# New ports collection makefile for:	yolk
# Date created:		2007-03-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yolk
PORTVERSION=	0.0.6
CATEGORIES=	misc python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/y/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python tool for listing packages installed by setuptools

BUILD_DEPENDS+=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${BUILD_DEPENDS}

OPTIONS=	PYPI_RSS	"Enable fetching PyPI RSS feed" On
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined (NOPORTDOCS)
DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
.if !defined (NO_INSTALL_MAN)
MAN1=	${PORTNAME}.1
.endif
.endif

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PYYOLK_EGG}

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYYOLK_EGG=${PYYOLK_EGG} PYYOLK_EGG_VER=${PYYOLK_EGG_VER} \
		PORTEXAMPLES=${PORTEXAMPLES}

EASY_INSTALL_CMD=	easy_install-${PYTHON_VER}

PYYOLK_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg
PYYOLK_EGG_VER=	"${PORTNAME}==${PORTVERSION}"

.include <bsd.port.pre.mk>

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKSRC}/docs && ${FIND} api -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
.if !defined (NO_INSTALL_MAN)
	@${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.1 ${MANPREFIX}/man/man1/${PORTNAME}.1
.endif
.endif
.if !defined (WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} ";"
.endif

.if defined (WITH_PYPI_RSS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

.if defined (WITHOUT_EXAMPLES)
PORTEXAMPLES=	"@comment "
.else
EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	""
.endif

.include <bsd.port.post.mk>
