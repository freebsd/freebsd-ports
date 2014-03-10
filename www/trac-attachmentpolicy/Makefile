# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	attachmentpolicy
PORTVERSION=	0.1.0.${SVN_REV}
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		http://trac-hacks.org/changeset/${SVN_REV}/attachmentpolicyplugin?old_path=/&format=zip&filename=/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	gaod@hychen.org
COMMENT=	Provides delete permission to Trac normal user

LICENSE=	BSD

SVN_REV=	12775

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
PYDISTUTILS_PKGNAME=	Attachment_Policy_Plugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION:C/.${SVN_REV}//g}
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
