# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	addcomment
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}macro-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add formatted comments to wiki pages

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		trac-macropost>0:${PORTSDIR}/www/trac-macropost

WRKSRC=		${WRKDIR}/${PORTNAME}macro
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracAddCommentMacro
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
