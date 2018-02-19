# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	keywords
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	trackeywordsplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for using pre-configured keywords

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	trac>=0.11:www/trac

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/trackeywordsplugin/0.11
NO_ARCH=	yes
REL=		7273

post-extract:
# Fix misplaced Genshi template: https://trac-hacks.org/ticket/6104
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/templates/keywords.html ${WRKSRC}/trackeywords/templates/
# Seems like web_ui.py was misplaced too.
	@${MV} ${WRKDIR}/trackeywordsplugin/0.10/trackeywords/web_ui.py ${WRKSRC}/trackeywords/

.include <bsd.port.mk>
