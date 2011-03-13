# New ports collection makefile for:	yolk
# Date created:		2007-03-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yolk
PORTVERSION=	0.4.1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
MASTER_SITE_SUBDIR=	source/y/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python tool for listing packages installed by setuptools

OPTIONS=	PYPI_RSS	"Enable fetching PyPI RSS feed" On
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.if !defined (NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 271 || ${PYTHON_REL} == 320
IGNORE=	does not work with ${PYTHON_VERSION} (see http://goo.gl/SZpDN)
.endif

post-install:
.if !defined (NO_INSTALL_MANPAGES)
	@${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.1 ${MANPREFIX}/man/man1/${PORTNAME}.1
.endif
.if !defined (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} ";"
	@cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} ";"
.endif

.if defined (WITH_PYPI_RSS) && defined(PYTHON_VER) && ${PYTHON_VER} < 2.5
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

.if !defined (NOPORTEXAMPLES)
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

.include <bsd.port.post.mk>
