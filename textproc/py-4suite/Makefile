# New ports collection makefile for:	py-4suite
# Date created:		16 March 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	4suite
PORTVERSION=	0.10.2
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.4suite.org/pub/4Suite/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	4Suite-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.if ${PYTHON_VERSION} == "python1.5"
PLIST_SUB+=	PACKAGE_DIR=xml PYTHON2_ONLY="@comment "
.else
PLIST_SUB+=	PACKAGE_DIR=_xmlplus PYTHON2_ONLY=""
.endif

post-patch:
.if defined(NOPORTDOCS)
	@ ${PERL} -pi -e '/^data_files\.extend/ && s/^/#/' ${WRKSRC}/setup.py
.endif

do-build:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 \
	  --prefix=${PREFIX}

.include <bsd.port.post.mk>
