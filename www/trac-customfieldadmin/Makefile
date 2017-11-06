# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	customfieldadmin
PORTVERSION=	0.2.2.6485
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Web interface to administer Trac ticket custom fields

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	tracd:www/trac

PORTSCOUT=	skipv:0.2.6485

USES=		python:2 zip

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
