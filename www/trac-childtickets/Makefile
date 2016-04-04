# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	childtickets
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Support for having child-tickets in Trac

LICENSE=	BSD3CLAUSE

RUN_DEPENDS+=	trac>=0.12:www/trac

USES=		python:2 zip

WRKSRC=		${WRKDIR}/childticketsplugin/0.12

USE_PYTHON=	distutils autoplist

SUB_FILES=	pkg-message

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
