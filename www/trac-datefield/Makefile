# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	datefield
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	datefieldplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for creating date fields

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracDateField
WRKSRC=		${WRKDIR}/datefieldplugin/0.11
REL=		7267
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
