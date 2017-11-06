# $FreeBSD$

PORTNAME=	estimator
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Produce detailed range-based estimations for Trac tickets

RUN_DEPENDS=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
