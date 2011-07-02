# New ports collection makefile for:	trac-gitplugin
# Date created:				2 November 2009
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	gitplugin
PORTVERSION=	0.12.0.5
CATEGORIES=	www devel python
MASTER_SITES=	https://download.github.com/ \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	hvr-trac-git-plugin-v${PORTVERSION}-15-g${GITPLUGIN_HASH}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Git plugin for Trac

RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		tracd:${PORTSDIR}/www/trac

LICENSE=	GPLv2

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracGit
PYDISTUTILS_PKGVERSION=	${PORTVERSION}dev
WRKSRC=			${WRKDIR}/hvr-trac-git-plugin-${GITPLUGIN_HASH}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

GITPLUGIN_HASH=	2c21931

.include <bsd.port.mk>
