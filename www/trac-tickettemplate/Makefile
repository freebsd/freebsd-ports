# Created by: Eygene Ryabinkin <rea@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tickettemplate
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/trac-${PORTNAME}/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}plugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for making ticket templates

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracTicketTemplate

WRKSRC=		${WRKDIR}/trac${PORTNAME}plugin/0.11
REL=		10605
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
