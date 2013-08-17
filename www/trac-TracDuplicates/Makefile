# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	TracDuplicates
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	GH
PKGNAMEPREFIX=	trac-

MAINTAINER=	gslin@gslin.org
COMMENT=	Notice original ticket to dupe one

LICENSE=	BSD

RUN_DEPENDS=	trac>=0:${PORTSDIR}/www/trac

GH_ACCOUNT=	nmaier
GH_COMMIT=	22976dd
USE_GITHUB=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
