# New ports collection makefile for: trac-tweakui
# Date created:                      Dec 09 2008
# Whom:                              glarkin
#
# $FreeBSD$
#

PORTNAME=	tweakui
PORTVERSION=	0.1.7413
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Easily tweak Trac pages with Javascript expressions

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(css|html|js|py|txt)$

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin/0.11
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracTweakUI
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}
PLIST_SUB+=	EGGVERSION="${PORTVERSION:R}" PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/tractweakui/htdocs && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
