# New ports collection makefile for:	trac-gitplugin
# Date created:				2 November 2009
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	gitplugin
PORTVERSION=	0.12.0.2.7757
CATEGORIES=	www devel python
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}-r${PORTVERSION:E}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Git plugin for Trac

RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
LICENSE=	GPLv2

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes
PYDISTUTILS_PKGNAME=	TracGit
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}dev
WRKSRC=			${WRKDIR}/${PORTNAME}/${PORTVERSION:C/(.[0-9]+){3}$//}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include <bsd.port.mk>
