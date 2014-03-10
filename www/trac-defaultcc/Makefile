# Created by: Eygene Ryabinkin <rea@FreeBSD.org>
# $FreeBSD$

PORTNAME=	defaultcc
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/trac-${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin that adds default CC value for tickets

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=	2
USES=		zip

USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Default_CC
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/trunk
REL=		10605

.include <bsd.port.mk>
