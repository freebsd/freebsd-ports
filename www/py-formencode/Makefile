# New ports collection makefile for:	py-formencode
# Date created:		2005-11-16
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	formencode
PORTVERSION=	0.7.1
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/F/FormEncode/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormEncode-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	HTML form validation, generation, and conversion package

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GETTEXT=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESSDIR=	${PREFIX}/share/examples/py-${PORTNAME}
FORMENCODEVER?=	${PORTVERSION}
PYTHONVER?=	${PYTHON_VERSION:S/^python//}
PLIST_SUB=	PYFORMENCODE_EGG=${PYFORMENCODE_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	EGG="FormEncode==${FORMENCODEVER}" \
		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"

PORTDOCS=	*

PYFORMENCODE_EGG=	FormEncode-${FORMENCODEVER}-py${PYTHONVER}.egg

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
