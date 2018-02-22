# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	attachmentpolicy
PORTVERSION=	0.1.0.${SVN_REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		http://trac-hacks.org/changeset/${SVN_REV}/attachmentpolicyplugin?old_path=/&format=zip&filename=/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	gaod@hychen.org
COMMENT=	Provides delete permission to Trac normal user

LICENSE=	BSD3CLAUSE

SVN_REV=	12775

RUN_DEPENDS+=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

.include <bsd.port.mk>
