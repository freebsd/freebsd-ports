# New ports collection makefile for:	py-rssdler
# Date created:		02 May 2010
# Whom:			Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rssdler
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swell.k@gmail.com
COMMENT=	Automatically grab link elements of an RSS feed

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=4.1:${PORTSDIR}/textproc/py-feedparser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=4.1:${PORTSDIR}/textproc/py-feedparser

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

OPTIONS=	MECHANIZE "Retrieve pages with mechanize" On
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MECHANIZE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mechanize>=0.2:${PORTSDIR}/www/py-mechanize
.endif

.include <bsd.port.post.mk>
