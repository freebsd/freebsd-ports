# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	down
PORTVERSION=	0.0.1.r11
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracDown-${PORTVERSION:E}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Trac plugin for listing released downloads

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracDown
PYDISTUTILS_PKGVERSION=	0.0.1

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
