# New ports collection makefile for:	synce-sync-engine
# Date created:				27 September 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME?=	sync-engine
PORTVERSION=	0.13
CATEGORIES?=	palm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	synce
DISTNAME=	sync-engine-${PORTVERSION}

MAINTAINER?=	avl@FreeBSD.org
COMMENT?=	Synchronization Engine for Windows Mobile devices

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/pyrtfcomp.so:${PORTSDIR}/archivers/py-librtfcomp \
		${PYTHON_SITELIBDIR}/pyrra.so:${PORTSDIR}/palm/py-synce-librra \
		${PYTHON_SITELIBDIR}/pyrapi2.so:${PORTSDIR}/palm/py-synce-librapi2

.if defined(ENGINE_VER) && defined(PLUGINDIR)
NO_BUILD=	yes
USE_PYTHON_RUN=	yes
PLIST_SUB=	PLUGINDIR=${PLUGINDIR}
PLIST=		${PKGDIR}/pkg-plist.plugin
.else
PKGNAMEPREFIX=	synce-
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
.endif

.include <bsd.port.pre.mk>

.if defined(ENGINE_VER) && defined(PLUGINDIR)
do-install:
	@${MKDIR} ${PREFIX}/${PLUGINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/synce-opensync-plugin-${ENGINE_VER}x.py \
		${PREFIX}/${PLUGINDIR}/synce-opensync-plugin.py
.endif

.include <bsd.port.post.mk>
