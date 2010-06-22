# New ports collection makefile for:	flexget
# Date created:		Fri Mar  5 04:02:22 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flexget
PORTVERSION=	1.0.r1305
CATEGORIES=	www python
MASTER_SITES=	http://download.flexget.com/unstable/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYFLEXGET_EGG}
EXTRACT_SUFX=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Program to automate downloading from different sources

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>0.5:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pygooglechart>=0:${PORTSDIR}/graphics/py-pygooglechart \
		${PYTHON_PKGNAMEPREFIX}progressbar>=0:${PORTSDIR}/misc/py-progressbar \
		${PYTHON_PKGNAMEPREFIX}pynzb>=0:${PORTSDIR}/news/py-pynzb \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}rss2gen>=0:${PORTSDIR}/textproc/py-rss2gen \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.11:${PORTSDIR}/www/py-html5lib

LICENSE=	MIT

USE_ZIP=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info
NO_WRKSUBDIR=	yes

# Distfile
PYFLEXGET_EGG=	FlexGet-${PORTVERSION:R}${PORTVERSION:E}-py2.6.egg

# Prepare script
SUB_FILES=	${PORTNAME}.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-extract:
# remove compiled files
	@${FIND} ${WRKDIR} \
		\( -name "*.pyc" -o -name "*.pyo" \) \
		-exec ${RM} -f {} \;

pre-configure:
# Prepare new setup.py
	@${SED} \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		-e 's|%%VERSION%%|${PORTVERSION}|' \
		${FILESDIR}/setup.py.in \
		> ${WRKSRC}/${PYSETUP}

post-install:
# Install script
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
