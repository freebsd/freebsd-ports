# Created by: sutra
# $FreeBSD$

PORTNAME=	TracSpamFilter
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	www devel python
MASTER_SITES=	http://zhoushuqun.com/files/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	trac-

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Allow different ways to reject contributions that contain spam

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}dev

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
